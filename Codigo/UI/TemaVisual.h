#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;

// Solo presentacion: no modifica datos, seleccion, eventos de negocio ni navegacion.
public ref class TemaVisual abstract sealed {
private:
    static Image^ cargarFondo(int paso) {
        array<String^>^ claves = gcnew array<String^>{"configuracion","editor","seleccion","ejecucion","resultado"};
        String^ ruta = System::IO::Path::Combine(Application::StartupPath,
            System::IO::Path::Combine("Assets", "fondo-" + claves[paso-1] + ".png"));
        if (!System::IO::File::Exists(ruta)) return nullptr;
        try {
            Image^ original = Image::FromFile(ruta);
            // La copia permite reemplazar el PNG sin dejar el archivo bloqueado.
            try { return gcnew Bitmap(original); }
            finally { delete original; }
        }
        catch (System::IO::IOException^) { return nullptr; }
        catch (UnauthorizedAccessException^) { return nullptr; }
        catch (ArgumentException^) { return nullptr; }
        catch (OutOfMemoryException^) { return nullptr; }
    }

    static void liberarFondo(Object^ sender, EventArgs^) {
        Form^ form = safe_cast<Form^>(sender);
        if (form->BackgroundImage != nullptr) { delete form->BackgroundImage; form->BackgroundImage = nullptr; }
    }

    static void fondoEstado(Object^ sender, EventArgs^) {
        Label^ etiqueta = safe_cast<Label^>(sender);
        etiqueta->Visible = !String::IsNullOrEmpty(etiqueta->Text);
        etiqueta->BackColor = Color::White;
        if (etiqueta->Visible) {
            Size texto = TextRenderer::MeasureText(etiqueta->Text, etiqueta->Font,
                Size(etiqueta->Width - 18, Int32::MaxValue), TextFormatFlags::WordBreak);
            etiqueta->Height = Math::Max(32, Math::Min(64, texto.Height + 12));
        }
    }
    static GraphicsPath^ contorno(Rectangle rect, int radio) {
        GraphicsPath^ path = gcnew GraphicsPath();
        int diametro = radio * 2;
        path->AddArc(rect.X, rect.Y, diametro, diametro, 180, 90);
        path->AddArc(rect.Right - diametro, rect.Y, diametro, diametro, 270, 90);
        path->AddArc(rect.Right - diametro, rect.Bottom - diametro, diametro, diametro, 0, 90);
        path->AddArc(rect.X, rect.Bottom - diametro, diametro, diametro, 90, 90);
        path->CloseFigure();
        return path;
    }

    static void redondearBoton(Object^ sender, EventArgs^) {
        Button^ boton = safe_cast<Button^>(sender);
        if (boton->Width < 20 || boton->Height < 20) return;
        GraphicsPath^ path = contorno(Rectangle(0, 0, boton->Width, boton->Height), 9);
        Region^ anterior = boton->Region;
        boton->Region = gcnew Region(path);
        delete path;
        if (anterior != nullptr) delete anterior;
    }

    static void pintarTarjeta(Object^ sender, PaintEventArgs^ e) {
        GroupBox^ tarjeta = safe_cast<GroupBox^>(sender);
        e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;
        pintarFondoControl(tarjeta, e->Graphics);
        GraphicsPath^ path = contorno(Rectangle(0, 0, tarjeta->Width - 1, tarjeta->Height - 1), 12);
        SolidBrush^ fondo = gcnew SolidBrush(Color::White);
        Pen^ borde = gcnew Pen(Color::FromArgb(221, 229, 239));
        e->Graphics->FillPath(fondo, path);
        e->Graphics->DrawPath(borde, path);
        SolidBrush^ texto = gcnew SolidBrush(Color::FromArgb(29, 56, 82));
        e->Graphics->DrawString(tarjeta->Text, tarjeta->Font, texto, 12.0f, 5.0f);
        delete texto; delete borde; delete fondo; delete path;
    }

    static void pintarFondoControl(Control^ control, Graphics^ g) {
        Control^ padre = control->Parent;
        if (padre == nullptr) { g->Clear(SystemColors::Control); return; }
        if (dynamic_cast<GroupBox^>(padre) != nullptr) { g->Clear(Color::White); return; }
        g->Clear(padre->BackColor);
        if (padre->BackgroundImage != nullptr) {
            System::Drawing::Drawing2D::GraphicsState^ estado = g->Save();
            g->TranslateTransform((float)-control->Left, (float)-control->Top);
            g->DrawImage(padre->BackgroundImage, Rectangle(0, 0, padre->ClientSize.Width, padre->ClientSize.Height));
            g->Restore(estado);
        }
    }

    static void repintarControl(Object^ sender, EventArgs^) {
        safe_cast<Control^>(sender)->Invalidate();
    }

    static void pintarBoton(Object^ sender, PaintEventArgs^ e) {
        Button^ boton = safe_cast<Button^>(sender);
        Graphics^ g = e->Graphics;
        pintarFondoControl(boton, g);
        g->SmoothingMode = SmoothingMode::AntiAlias;
        bool encima = boton->ClientRectangle.Contains(boton->PointToClient(Control::MousePosition));
        bool presionado = boton->Capture &&
            (Control::MouseButtons & System::Windows::Forms::MouseButtons::Left) != System::Windows::Forms::MouseButtons::None;
        Color color = !boton->Enabled ? Color::FromArgb(222, 229, 237) :
            (presionado ? boton->FlatAppearance->MouseDownBackColor :
                (encima ? boton->FlatAppearance->MouseOverBackColor : boton->BackColor));
        GraphicsPath^ path = contorno(Rectangle(0, 0, boton->Width - 1, boton->Height - 1), 9);
        SolidBrush^ brush = gcnew SolidBrush(color);
        g->FillPath(brush, path);
        TextRenderer::DrawText(g, boton->Text, boton->Font, boton->ClientRectangle,
            boton->Enabled ? boton->ForeColor : Color::FromArgb(118, 134, 153),
            TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter | TextFormatFlags::SingleLine);
        if (boton->Focused)
            ControlPaint::DrawFocusRectangle(g, Rectangle(5, 5, boton->Width - 10, boton->Height - 10), boton->ForeColor, color);
        delete brush; delete path;
    }

    static void aplicarControles(Control^ raiz) {
        for each (Control^ c in raiz->Controls) {
            Button^ boton = dynamic_cast<Button^>(c);
            GroupBox^ tarjeta = dynamic_cast<GroupBox^>(c);
            ListBox^ lista = dynamic_cast<ListBox^>(c);
            ComboBox^ combo = dynamic_cast<ComboBox^>(c);
            NumericUpDown^ numero = dynamic_cast<NumericUpDown^>(c);
            Label^ etiqueta = dynamic_cast<Label^>(c);
            if (boton != nullptr) {
                bool secundario = boton->Name == "btnVolver" || boton->Name == "btnSalir" || boton->Name == "btnAnterior" || boton->Name == "btnReiniciar";
                bool eliminar = boton->Name == "btnEliminar";
                bool principal = boton->Name == "btnCrear" || boton->Name == "btnContinuar" || boton->Name == "btnEjecutar" || boton->Name == "btnSiguiente";
                Color color = eliminar ? Color::FromArgb(255, 232, 234) : (secundario ? Color::FromArgb(229, 236, 246) : (principal ? Color::FromArgb(13, 132, 139) : Color::FromArgb(46, 74, 119)));
                boton->FlatStyle = FlatStyle::Flat;
                boton->UseVisualStyleBackColor = false;
                boton->FlatAppearance->BorderSize = 0;
                boton->BackColor = color;
                boton->ForeColor = eliminar ? Color::FromArgb(168, 42, 62) : (secundario ? Color::FromArgb(42, 63, 90) : Color::White);
                boton->FlatAppearance->MouseOverBackColor = ControlPaint::Light(color, 0.12f);
                boton->FlatAppearance->MouseDownBackColor = ControlPaint::Dark(color, 0.10f);
                boton->Font = gcnew Font("Segoe UI", 9, FontStyle::Bold);
                boton->Cursor = Cursors::Hand;
                boton->Paint += gcnew PaintEventHandler(&TemaVisual::pintarBoton);
                boton->MouseEnter += gcnew EventHandler(&TemaVisual::repintarControl);
                boton->MouseLeave += gcnew EventHandler(&TemaVisual::repintarControl);
                boton->GotFocus += gcnew EventHandler(&TemaVisual::repintarControl);
                boton->LostFocus += gcnew EventHandler(&TemaVisual::repintarControl);
                boton->SizeChanged += gcnew EventHandler(&TemaVisual::redondearBoton);
                redondearBoton(boton, EventArgs::Empty);
            }
            else if (tarjeta != nullptr) {
                tarjeta->BackColor = Color::Transparent;
                tarjeta->ForeColor = Color::FromArgb(29, 56, 82);
                tarjeta->Font = gcnew Font("Segoe UI", 9, FontStyle::Bold);
                tarjeta->Paint += gcnew PaintEventHandler(&TemaVisual::pintarTarjeta);
            }
            else if (lista != nullptr) {
                lista->BackColor = Color::FromArgb(248, 250, 253);
                lista->ForeColor = Color::FromArgb(42, 63, 90);
                lista->BorderStyle = BorderStyle::FixedSingle;
                if (lista->Font->FontFamily->Name != "Consolas") lista->Font = gcnew Font("Segoe UI", 9);
            }
            else if (combo != nullptr || numero != nullptr) {
                c->Font = gcnew Font("Segoe UI", 9);
                c->BackColor = Color::FromArgb(248, 250, 253);
                c->ForeColor = Color::FromArgb(29, 56, 82);
                if (combo != nullptr) combo->FlatStyle = FlatStyle::Flat;
            }
            else if (etiqueta != nullptr) {
                if (etiqueta->Parent == raiz && dynamic_cast<Form^>(raiz) != nullptr) etiqueta->BackColor = Color::White;
                if (etiqueta->Name == "lblEstado") {
                    etiqueta->BorderStyle = BorderStyle::FixedSingle;
                    etiqueta->Padding = System::Windows::Forms::Padding(8, 5, 8, 5);
                    etiqueta->Height = 60;
                    etiqueta->TextChanged += gcnew EventHandler(&TemaVisual::fondoEstado);
                    fondoEstado(etiqueta, EventArgs::Empty);
                }
                etiqueta->Font = gcnew Font("Segoe UI", etiqueta->Font->Size, etiqueta->Font->Style);
                // Los mensajes dinamicos conservan sus colores de estado.
                if (etiqueta->Name != "lblEstado" && etiqueta->Name != "lblVerificacion")
                    etiqueta->ForeColor = Color::FromArgb(42, 63, 90);
                if (etiqueta->Name == "lblFlujoTotal" || etiqueta->Name == "lblFlujoMaximo") {
                    etiqueta->BackColor = Color::FromArgb(218, 243, 239);
                    etiqueta->ForeColor = Color::FromArgb(9, 105, 102);
                }
                if (etiqueta->Name == "lblFlujoMaximo") {
                    etiqueta->BorderStyle = BorderStyle::FixedSingle;
                    etiqueta->TextAlign = ContentAlignment::MiddleLeft;
                    etiqueta->Padding = System::Windows::Forms::Padding(6, 0, 6, 0);
                }
                if (etiqueta->Name == "lblVerificacion") {
                    etiqueta->BackColor = Color::FromArgb(248, 250, 253);
                    etiqueta->BorderStyle = BorderStyle::FixedSingle;
                    etiqueta->Height = 48;
                    etiqueta->TextAlign = ContentAlignment::MiddleLeft;
                    etiqueta->Padding = System::Windows::Forms::Padding(6, 0, 6, 0);
                }
            }
            else if (dynamic_cast<CheckBox^>(c) != nullptr || dynamic_cast<RadioButton^>(c) != nullptr) {
                c->Font = gcnew Font("Segoe UI", 9);
                c->ForeColor = Color::FromArgb(42, 63, 90);
            }
            aplicarControles(c);
        }
    }

public:
    static void aplicar(Form^ form, int paso, String^ titulo) {
        form->SuspendLayout();
        form->BackColor = Color::FromArgb(10, 22, 43);
        form->BackgroundImage = cargarFondo(paso);
        form->BackgroundImageLayout = ImageLayout::Stretch;
        form->Disposed += gcnew EventHandler(&TemaVisual::liberarFondo);
        aplicarControles(form);
        if (paso != 1) {
            for each (Control^ c in form->Controls) c->Top += 88;
            form->ClientSize = Size(form->ClientSize.Width, form->ClientSize.Height + 88);
        }
        else {
            for each (Control^ c in form->Controls)
                if (c->Name == "lblTitulo" || c->Name == "lblSubtitulo") c->Visible = false;
            form->ClientSize = Size(920, 440);
            for each (Control^ c in form->Controls) {
                if (c->Name == "gbConfig") c->Location = Point(32, 132);
                else if (c->Name == "btnCrear") c->Location = Point(32, 340);
                else if (c->Name == "btnSalir") c->Location = Point(252, 340);
            }
        }
        Panel^ cabecera = gcnew Panel();
        cabecera->Name = "cabeceraVisual";
        cabecera->BackColor = Color::FromArgb(22, 39, 63);
        cabecera->BorderStyle = BorderStyle::FixedSingle;
        cabecera->Bounds = Rectangle(15, 10, form->ClientSize.Width - 30, 64);
        cabecera->Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right;
        Label^ encabezado = gcnew Label();
        encabezado->Text = titulo;
        encabezado->Font = gcnew Font("Segoe UI", 17, FontStyle::Bold);
        encabezado->ForeColor = Color::White;
        encabezado->BackColor = Color::Transparent;
        encabezado->Bounds = Rectangle(18, 14, cabecera->Width - 150, 33);
        Label^ etapa = gcnew Label();
        etapa->Text = "PASO " + paso + " / 5";
        etapa->Font = gcnew Font("Segoe UI", 9, FontStyle::Bold);
        etapa->TextAlign = ContentAlignment::MiddleCenter;
        etapa->BackColor = Color::FromArgb(39, 63, 90);
        etapa->ForeColor = Color::FromArgb(116, 221, 207);
        etapa->Bounds = Rectangle(cabecera->Width - 112, 16, 94, 29);
        Panel^ acento = gcnew Panel();
        acento->BackColor = Color::FromArgb(38, 184, 167);
        acento->Bounds = Rectangle(0, 59, cabecera->Width * paso / 5, 3);
        cabecera->Controls->Add(encabezado);
        cabecera->Controls->Add(etapa);
        cabecera->Controls->Add(acento);
        form->Controls->Add(cabecera);
        form->ResumeLayout(false);
    }
};
