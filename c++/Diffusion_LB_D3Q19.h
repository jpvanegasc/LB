#include"constants.h"

#ifndef __AIR_POLLUTION_CPP_DIFFUSION_LB_D3Q19_H
#define __AIR_POLLUTION_CPP_DIFFUSION_LB_D3Q19_H

class Diffusion{
    private:
        double w[Q]; int V[D][Q];
        double *f = NULL,   *f_new = NULL;
    public:
        Diffusion(void);
        ~Diffusion();
        double rho(int position);
        double Jx(int position);
        double Jy(int position);
        double Jz(int position);
        double Jx_new(int ix, int iy, int iz);
        double Jy_new(int ix, int iy, int iz);
        double Jz_new(int ix, int iy, int iz);
        double f_neq(void);
        void collide(void);
        void propagate(void);
        void initialize(double rho0, double Ux0, double Uy0, double Uz0);
        void impose_fields(double v);
        void save(std::string filename, double v);
        void save_2D(std::string filename, int z_pos, double v);
        void print(double v);
};

#endif