/*******************************************************************************
    Copyright (C) 2014 Wright State University - All Rights Reserved
    Daniel P. Foose - Author

    This file is part of Vespucci.

    Vespucci is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Vespucci is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Vespucci.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/
#ifndef ARMA_EXT_H
#define ARMA_EXT_H
#include <QApplication>
#include <QVector>
#include <QMessageBox>
#include <mlpack/core.hpp>

using namespace arma;


namespace arma_ext
{
mat spdiags(mat B, ivec d, uword m, uword n);
bool svds(mat X, uword k, mat &U, vec &s, mat &V);
mat orth(mat X);
bool plsregress(mat X, mat Y, int components,
                mat &X_loadings, mat &Y_loadings,
                mat &X_scores, mat &Y_scores,
                mat &coefficients, mat &percent_variance, mat &fitted);
bool VCA(mat R, uword p, uvec &indices, mat &endmember_spectra,
         mat &projected_data, mat &fractional_abundances);
double estimate_snr(mat R, vec r_m, mat x);

mat sgolay(uword poly_order, uword window_size, uword deriv_order, uword scaling_factor);
mat sgolayfilt(mat x, uword poly_order, uword window_size, uword deriv_order, uword scaling_factor);
vec ApplyFilter(vec x, mat coefficients, uword window_size);
vec ApplyFilter(vec x, vec filter);
vec CreateMovingAverageFilter(uword window_size);
vec StandardScore(vec X);
mat StandardScoreMat(mat X);
uword min(uword a, uword b);
uword max(uword a, uword b);
vec MedianFilter(vec X, uword window_size);
mat MedianFilterMat(mat X, uword window_size);

//Peak determination
double IntegratePeak(vec X, uword min_index, uword max_index, double abscissa_step, vec &baseline);
vec IntegratePeakMat(mat X, vec abscissa, double &min, double &max, mat &baselines, uvec &boundaries);
mat IntegratePeaksMat(mat X, vec abscissa,
                      double &first_min, double &first_max,
                      double &second_min, double &second_max,
                      mat &first_baselines, mat &second_baselines, uvec &boundaries);

double FindPeakMax(vec X, uword min_index, uword max_index, uword &position);
vec FindPeakMaxMat(mat X, vec abscissa, double &min, double &max, vec &positions);
mat FindPeakMaxesMat(mat X, vec abscissa,
                     double &first_min, double &first_max,
                     double &second_min, double &second_max,
                     mat positions);

double FindBandwidth(vec X, uword min_index, uword max_index, vec &midline, vec &baseline, double abscissa_step);
vec FindBandwidthMat(mat X, vec abscissa, double &min, double &max, mat &midlines, mat &baselines, uvec &boundaries);
vec CorrelationMat(mat X, vec control);

int HySime(mat y, mat n, mat Rn, mat &Ek);
void EstimateAdditiveNoise(mat &noise, mat &noise_correlation, mat sample);
}

#endif // ARMA_EXT_H
