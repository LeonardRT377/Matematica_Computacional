#pragma once
#include "Grafo.h"
#include "PasoAlgoritmo.h"
#include "ResultadoCorte.h"

using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

public ref class GrafoVisual {
private:
    void dibujarLeyenda(Graphics^ g, array<String^>^ textos, array<Color>^ colores) {
        Font^ fuente = gcnew Font("Segoe UI", 8, FontStyle::Regular);
        float ancho = 16.0f;
        for each (String^ texto in textos) ancho += g->MeasureString(texto, fuente).Width + 30.0f;
        SolidBrush^ fondo = gcnew SolidBrush(Color::FromArgb(248, 250, 253));
        Pen^ borde = gcnew Pen(Color::FromArgb(221, 229, 239));
        g->FillRectangle(fondo, 10.0f, 10.0f, ancho, 28.0f);
        g->DrawRectangle(borde, 10.0f, 10.0f, ancho, 28.0f);
        SolidBrush^ tinta = gcnew SolidBrush(Color::FromArgb(42, 63, 90));
        float x = 19.0f;
        for (int i = 0; i < textos->Length; i++) {
            SolidBrush^ muestra = gcnew SolidBrush(colores[i]);
            g->FillEllipse(muestra, x, 19.0f, 9.0f, 9.0f);
            g->DrawString(textos[i], fuente, tinta, x + 15.0f, 16.0f);
            x += g->MeasureString(textos[i], fuente).Width + 30.0f;
            delete muestra;
        }
        delete tinta; delete borde; delete fondo; delete fuente;
    }

    Dictionary<int, Point>^ posiciones;
    int radioVertice;
    int anchoPanel;
    int altoPanel;

    void dibujarFlecha(Graphics^ g, Point p1, Point p2, Pen^ pen) {
        g->DrawLine(pen, p1, p2);
        double ang = Math::Atan2((double)(p2.Y - p1.Y), (double)(p2.X - p1.X));
        int len = 12;
        double a1 = ang - Math::PI / 6;
        double a2 = ang + Math::PI / 6;
        Point pa = Point((int)(p2.X - len * Math::Cos(a1)), (int)(p2.Y - len * Math::Sin(a1)));
        Point pb = Point((int)(p2.X - len * Math::Cos(a2)), (int)(p2.Y - len * Math::Sin(a2)));
        array<Point>^ tri = gcnew array<Point>(3);
        tri[0] = p2; tri[1] = pa; tri[2] = pb;
        SolidBrush^ b = gcnew SolidBrush(pen->Color);
        g->FillPolygon(b, tri);
        delete b;
    }

    Point puntoBorde(Point centro, Point otro, int radio) {
        double ang = Math::Atan2((double)(otro.Y - centro.Y), (double)(otro.X - centro.X));
        return Point((int)(centro.X + radio * Math::Cos(ang)), (int)(centro.Y + radio * Math::Sin(ang)));
    }

    bool esAristaDelCamino(int idArista, bool inversa, List<AristaResidual^>^ caminoRes) {
        if (caminoRes == nullptr) return false;
        for each (AristaResidual^ r in caminoRes)
            if (r->getIdAristaOriginal() == idArista && r->getEsInversa() == inversa) return true;
        return false;
    }

    bool esVerticeDelCamino(int id, List<int>^ camino) {
        if (camino == nullptr) return false;
        return camino->Contains(id);
    }

    void dibujarVertices(Graphics^ g, Grafo^ grafo, List<int>^ camino, Dictionary<int, bool>^ enS, bool colorearCorte) {
        for each (Vertice^ v in grafo->getVertices()) {
            int id = v->getId();
            if (!posiciones->ContainsKey(id)) continue;
            Point p = posiciones[id];
            bool enCamino = esVerticeDelCamino(id, camino);
            bool esFicticio = (v->getNombre() == "SUPER_FUENTE" || v->getNombre() == "SUPER_SUMIDERO");
            Color col;
            if (esFicticio) col = Color::FromArgb(255, 220, 180);
            else if (colorearCorte) {
                bool enSC = enS != nullptr && enS->ContainsKey(id) && enS[id];
                col = enSC ? Color::FromArgb(180, 255, 180) : Color::FromArgb(255, 180, 180);
            }
            else col = enCamino ? Color::FromArgb(255, 200, 100) : Color::FromArgb(180, 220, 255);
            Rectangle rect = Rectangle(p.X - radioVertice, p.Y - radioVertice, radioVertice * 2, radioVertice * 2);
            SolidBrush^ br = gcnew SolidBrush(col);
            g->FillEllipse(br, rect);
            delete br;
            Color borde = colorearCorte
                ? ((enS != nullptr && enS->ContainsKey(id) && enS[id]) ? Color::Green : Color::DarkRed)
                : (enCamino ? Color::OrangeRed : (esFicticio ? Color::DarkOrange : Color::FromArgb(30, 80, 160)));
            float grosor = enCamino ? 3.5f : (esFicticio ? 3.0f : 2.0f);
            Pen^ penBorde = gcnew Pen(borde, grosor);
            g->DrawEllipse(penBorde, rect);
            delete penBorde;
            Font^ f = gcnew Font("Segoe UI", 9, FontStyle::Bold);
            SizeF sz = g->MeasureString(v->getNombre(), f);
            g->DrawString(v->getNombre(), f, gcnew SolidBrush(Color::Black), p.X - sz.Width / 2, p.Y - sz.Height / 2);
            delete f;
        }
    }

public:
    GrafoVisual() {
        posiciones = gcnew Dictionary<int, Point>();
        radioVertice = 26;
        anchoPanel = 800;
        altoPanel = 500;
    }

    ~GrafoVisual() {}

    void calcularPosiciones(Grafo^ grafo, int ancho, int alto) {
        anchoPanel = ancho;
        altoPanel = alto;
        posiciones->Clear();
        if (grafo == nullptr || grafo->getVertices()->Count == 0) return;
        int cx = ancho / 2;
        int cy = alto / 2;
        int r = (int)(Math::Min(ancho, alto) * 0.38);
        if (r < 80) r = 80;
        List<Vertice^>^ normales = gcnew List<Vertice^>();
        Vertice^ superF = nullptr;
        Vertice^ superT = nullptr;
        for each (Vertice^ v in grafo->getVertices()) {
            if (v->getNombre() == "SUPER_FUENTE") superF = v;
            else if (v->getNombre() == "SUPER_SUMIDERO") superT = v;
            else normales->Add(v);
        }
        int nn = normales->Count;
        for (int i = 0; i < nn; i++) {
            double ang = 2 * Math::PI * i / nn - Math::PI / 2;
            posiciones[normales[i]->getId()] = Point((int)(cx + r * Math::Cos(ang)), (int)(cy + r * Math::Sin(ang)));
        }
        if (superF != nullptr) posiciones[superF->getId()] = Point(40, cy);
        if (superT != nullptr) posiciones[superT->getId()] = Point(ancho - 40, cy);
    }

    void calcularPosiciones(Grafo^ grafo) { calcularPosiciones(grafo, anchoPanel, altoPanel); }
    Dictionary<int, Point>^ getPosiciones() { return posiciones; }

    void dibujar(Graphics^ g, Grafo^ grafo) {
        if (grafo == nullptr || g == nullptr) return;
        if (posiciones->Count == 0) calcularPosiciones(grafo);
        g->SmoothingMode = SmoothingMode::AntiAlias;
        g->Clear(Color::White);
        for each (Arista^ a in grafo->getAristas()) {
            int o = a->getOrigen()->getId();
            int d = a->getDestino()->getId();
            if (!posiciones->ContainsKey(o) || !posiciones->ContainsKey(d)) continue;
            Point p1 = puntoBorde(posiciones[o], posiciones[d], radioVertice);
            Point p2 = puntoBorde(posiciones[d], posiciones[o], radioVertice);
            bool esFicticia = (a->getOrigen()->getNombre() == "SUPER_FUENTE" || a->getDestino()->getNombre() == "SUPER_SUMIDERO");
            Pen^ pen = gcnew Pen(esFicticia ? Color::Gray : Color::FromArgb(60, 60, 60), 2.0f);
            if (esFicticia) pen->DashStyle = DashStyle::Dash;
            dibujarFlecha(g, p1, p2, pen);
            delete pen;
            int mx = (p1.X + p2.X) / 2;
            int my = (p1.Y + p2.Y) / 2;
            String^ txt = esFicticia ? L"\u221E" : (a->getFlujo() + "/" + a->getCapacidad());
            Font^ f = gcnew Font("Segoe UI", 8, FontStyle::Bold);
            SizeF sz = g->MeasureString(txt, f);
            g->FillRectangle(gcnew SolidBrush(Color::FromArgb(255, 255, 200)), mx - sz.Width / 2 - 2, my - sz.Height / 2 - 1, sz.Width + 4, sz.Height + 2);
            g->DrawString(txt, f, gcnew SolidBrush(Color::Black), mx - sz.Width / 2, my - sz.Height / 2);
            delete f;
        }
        dibujarVertices(g, grafo, nullptr, nullptr, false);
    }

    void dibujarPaso(Graphics^ g, Grafo^ grafo, PasoAlgoritmo^ paso) {
        if (grafo == nullptr || g == nullptr) return;
        if (posiciones->Count == 0) calcularPosiciones(grafo);
        g->SmoothingMode = SmoothingMode::AntiAlias;
        g->Clear(Color::White);
        Dictionary<int, int>^ flujos = paso != nullptr ? paso->getFlujosAristas() : nullptr;
        List<AristaResidual^>^ caminoRes = paso != nullptr ? paso->getCaminoResidual() : nullptr;
        List<int>^ camino = paso != nullptr ? paso->getCamino() : nullptr;

        for each (Arista^ a in grafo->getAristas()) {
            int o = a->getOrigen()->getId();
            int d = a->getDestino()->getId();
            if (!posiciones->ContainsKey(o) || !posiciones->ContainsKey(d)) continue;
            Point p1 = puntoBorde(posiciones[o], posiciones[d], radioVertice);
            Point p2 = puntoBorde(posiciones[d], posiciones[o], radioVertice);
            int flujo = (flujos != nullptr && flujos->ContainsKey(a->getId())) ? flujos[a->getId()] : 0;
            bool esFicticia = (a->getOrigen()->getNombre() == "SUPER_FUENTE" || a->getDestino()->getNombre() == "SUPER_SUMIDERO");
            bool enCamino = esAristaDelCamino(a->getId(), false, caminoRes) || esAristaDelCamino(a->getId(), true, caminoRes);
            Pen^ pen;
            if (enCamino) pen = gcnew Pen(Color::OrangeRed, 3.5f);
            else if (esFicticia) { pen = gcnew Pen(Color::Gray, 2.0f); pen->DashStyle = DashStyle::Dash; }
            else pen = gcnew Pen(Color::FromArgb(60, 60, 60), 2.0f);
            dibujarFlecha(g, p1, p2, pen);
            delete pen;
            int mx = (p1.X + p2.X) / 2;
            int my = (p1.Y + p2.Y) / 2;
            String^ txt = esFicticia ? L"\u221E" : (flujo + "/" + a->getCapacidad());
            Font^ f = gcnew Font("Segoe UI", 8, FontStyle::Bold);
            SizeF sz = g->MeasureString(txt, f);
            Color bg = enCamino ? Color::FromArgb(255, 230, 180) : Color::FromArgb(255, 255, 200);
            g->FillRectangle(gcnew SolidBrush(bg), mx - sz.Width / 2 - 2, my - sz.Height / 2 - 1, sz.Width + 4, sz.Height + 2);
            g->DrawString(txt, f, gcnew SolidBrush(enCamino ? Color::DarkRed : Color::Black), mx - sz.Width / 2, my - sz.Height / 2);
            delete f;
        }
        dibujarVertices(g, grafo, camino, nullptr, false);
    }

    void dibujarResidual(Graphics^ g, Grafo^ grafo, PasoAlgoritmo^ paso) {
        if (grafo == nullptr || g == nullptr || paso == nullptr) return;
        if (posiciones->Count == 0) calcularPosiciones(grafo);
        g->SmoothingMode = SmoothingMode::AntiAlias;
        g->Clear(Color::White);
        // El camino se encontro en la red anterior al aumento.
        List<AristaResidual^>^ red = paso->getEsFinal() ? paso->getRedResidual() : paso->getRedResidualAnterior();
        List<AristaResidual^>^ caminoRes = paso->getCaminoResidual();

        if (red != nullptr) {
            for each (AristaResidual^ r in red) {
                int o = r->getIdOrigen();
                int d = r->getIdDestino();
                if (!posiciones->ContainsKey(o) || !posiciones->ContainsKey(d)) continue;
                Point p1 = puntoBorde(posiciones[o], posiciones[d], radioVertice);
                Point p2 = puntoBorde(posiciones[d], posiciones[o], radioVertice);
                bool enCamino = esAristaDelCamino(r->getIdAristaOriginal(), r->getEsInversa(), caminoRes);
                bool inversa = r->getEsInversa();
                Pen^ pen;
                if (enCamino) pen = gcnew Pen(Color::OrangeRed, 3.5f);
                else if (inversa) { pen = gcnew Pen(Color::FromArgb(120, 120, 220), 1.5f); pen->DashStyle = DashStyle::Dash; }
                else pen = gcnew Pen(Color::FromArgb(60, 60, 60), 2.0f);
                dibujarFlecha(g, p1, p2, pen);
                delete pen;
                int mx = (p1.X + p2.X) / 2;
                int my = (p1.Y + p2.Y) / 2;
                String^ txt = r->getCapacidadResidual().ToString();
                if (inversa) txt += "*";
                Font^ f = gcnew Font("Segoe UI", 7, FontStyle::Regular);
                SizeF sz = g->MeasureString(txt, f);
                Color bg = enCamino ? Color::FromArgb(255, 230, 180) : (inversa ? Color::FromArgb(230, 230, 255) : Color::FromArgb(255, 255, 220));
                g->FillRectangle(gcnew SolidBrush(bg), mx - sz.Width / 2 - 2, my - sz.Height / 2 - 1, sz.Width + 4, sz.Height + 2);
                g->DrawString(txt, f, gcnew SolidBrush(Color::Black), mx - sz.Width / 2, my - sz.Height / 2);
                delete f;
            }
        }
        dibujarVertices(g, grafo, paso->getCamino(), nullptr, false);
        dibujarLeyenda(g,
            gcnew array<String^>{paso->getEsFinal() ? "Residual final" : "Antes del aumento", "Inversa (*)", "Camino"},
            gcnew array<Color>{Color::DimGray, Color::FromArgb(120, 120, 220), Color::OrangeRed});
    }

    void dibujarCorte(Graphics^ g, Grafo^ grafo, ResultadoCorte^ corte, Dictionary<int, int>^ flujos) {
        if (grafo == nullptr || g == nullptr) return;
        if (posiciones->Count == 0) calcularPosiciones(grafo);
        g->SmoothingMode = SmoothingMode::AntiAlias;
        g->Clear(Color::White);
        Dictionary<int, bool>^ enS = gcnew Dictionary<int, bool>();
        Dictionary<int, bool>^ esAristaCorte = gcnew Dictionary<int, bool>();
        if (corte != nullptr) {
            for each (int id in corte->getConjuntoS()) enS[id] = true;
            for each (Arista^ a in corte->getAristasCorte()) esAristaCorte[a->getId()] = true;
        }
        for each (Arista^ a in grafo->getAristas()) {
            int o = a->getOrigen()->getId();
            int d = a->getDestino()->getId();
            if (!posiciones->ContainsKey(o) || !posiciones->ContainsKey(d)) continue;
            Point p1 = puntoBorde(posiciones[o], posiciones[d], radioVertice);
            Point p2 = puntoBorde(posiciones[d], posiciones[o], radioVertice);
            bool esCorte = esAristaCorte->ContainsKey(a->getId()) && esAristaCorte[a->getId()];
            bool esFicticia = (a->getOrigen()->getNombre() == "SUPER_FUENTE" || a->getDestino()->getNombre() == "SUPER_SUMIDERO");
            int flujo = (flujos != nullptr && flujos->ContainsKey(a->getId())) ? flujos[a->getId()] : 0;
            Pen^ pen;
            if (esCorte) pen = gcnew Pen(Color::Red, 4.0f);
            else if (esFicticia) { pen = gcnew Pen(Color::Gray, 2.0f); pen->DashStyle = DashStyle::Dash; }
            else pen = gcnew Pen(Color::FromArgb(60, 60, 60), 2.0f);
            dibujarFlecha(g, p1, p2, pen);
            delete pen;
            int mx = (p1.X + p2.X) / 2;
            int my = (p1.Y + p2.Y) / 2;
            String^ txt = esFicticia ? L"\u221E" : (flujo + "/" + a->getCapacidad());
            Font^ f = gcnew Font("Segoe UI", 8, esCorte ? FontStyle::Bold : FontStyle::Regular);
            SizeF sz = g->MeasureString(txt, f);
            Color bg = esCorte ? Color::FromArgb(255, 180, 180) : Color::FromArgb(255, 255, 200);
            g->FillRectangle(gcnew SolidBrush(bg), mx - sz.Width / 2 - 2, my - sz.Height / 2 - 1, sz.Width + 4, sz.Height + 2);
            g->DrawString(txt, f, gcnew SolidBrush(esCorte ? Color::DarkRed : Color::Black), mx - sz.Width / 2, my - sz.Height / 2);
            delete f;
        }
        dibujarVertices(g, grafo, nullptr, enS, true);
        dibujarLeyenda(g, gcnew array<String^>{"S", "T", "Corte"},
            gcnew array<Color>{Color::Green, Color::FromArgb(220, 110, 110), Color::Red});
    }
};
