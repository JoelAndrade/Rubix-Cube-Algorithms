#ifndef NXN_H
#define NXN_H

#include "../main.h"

#include <iostream>
#include <SDL_CLasses.h>

class xx2 {
    public:
        SDL_Rect rect;
        
        xx2() {
            rect = {0, blockLength, blockLength, blockLength};
            rect.makeDimensions();
        }
        void fixString() {

        }

        void U(int size) {
            window.fillRect(&green, rect);

            for (int i = 1; i < size; ++i) {
                window.drawLine(rect.x + (blockLength*i)/size, rect.y, rect.x + (blockLength*i)/size, rect.bottomY, &black, 3, 1);
                window.drawLine(rect.x, rect.y + (blockLength*i)/size, rect.rightX, rect.y + (blockLength*i)/size, &black, 1, 3);
            }

            // window.drawLine(rect.x + blockLength/3, rect.y, rect.x + blockLength/3, rect.bottomY, &black, 3 , 1);
            // window.drawLine(rect.x + blockLength*2/3, rect.y, rect.x + blockLength*2/3, rect.y + blockLength, &black, 3, 1);
            // window.drawLine(rect.x, rect.y + blockLength/3, rect.x + blockLength, rect.y + blockLength/3, &black, 1, 3);
            // window.drawLine(rect.x, rect.y + blockLength*2/3, rect.x + blockLength, rect.y + blockLength*2/3, &black, 1, 3);
            window.drawRect(&violet, rect, 3, 3);
        }
        void UPrime() {

        }
        void u() {

        }
        void uPrime() {

        }
        void U2 () {
            
        }
        
        void D() {

        }
        void DPrime() {

        }
        void d() {

        }
        void dPrime() {

        }
        void D2 () {
            
        }
        

        void L() {

        }
        void LPrime() {
            
        }
        void l() {

        }
        void lPrime() {

        }
        void L2 () {
            
        }
        

        void R() {

        }
        void RPrime() {
            
        }
        void r() {

        }
        void rPrime() {

        }
        void R2 () {
            
        }
        

        void F() {

        }
        void FPrime() {
            
        }
        void f() {

        }
        void fPrime() {

        }
        void F2 () {
            
        }
        
        void B() {

        }
        void BPrime() {
            
        }
        void b() {

        }
        void bPrime() {

        }        
        void B2 () {
            
        }
        
        void x() {

        }
        void xPrime() {
            
        }
        void x2 () {
            
        }

        void y() {

        }
        void yPrime() {
            
        }
        void y2 () {
            
        }

        void z() {

        }
        void zPrime() {
            
        }
        void z2 () {
            
        }
};

class x3: public xx2 {
    public:
        std::string fixString(std::string text) {
            for (int i = 0; i < text.length(); ++i) {
                if (!(text[i] == 'U' || text[i] == 'u' 
                || text[i] == 'D' || text[i] == 'd' 
                || text[i] == 'L' || text[i] == 'l' 
                || text[i] == 'R' || text[i] == 'r' 
                || text[i] == 'F' || text[i] == 'f' 
                || text[i] == 'B' || text[i] == 'b' 
                || text[i] == 'x' || text[i] == 'y' || text[i] == 'z' 
                || text[i] == 'M' || text[i] == 'E' || text[i] == 'S' 
                || text[i] == '\'' || text[i] == '2'))
                {
                    text.erase(i, 1);
                    --i;
                }
            }
            return text;
        }

        void M() {

        }
        void MPrime() {
            
        }
        void M2 () {
            
        }
        
        void E() {

        }
        void EPrime() {
            
        }
        void E2 () {
            
        }
        
        void S() {

        }
        void SPrime() {
            
        }
        void S2 () {
            
        }
};

class x4 {
    public:
        void fixString() {
            
        }
};

class x5 {
    public:
        void fixString() {
            
        }
};

class x6 {
    public:
        void fixString() {
            
        }
};

class x7 {
    public:
        void fixString() {
                
            }
};
#endif // NXN_H