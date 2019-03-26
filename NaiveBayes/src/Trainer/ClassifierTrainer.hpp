//
//  ClassifierTrainer.hpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#ifndef ClassifierTrainer_hpp
#define ClassifierTrainer_hpp

#include "InputHandler.hpp"

constexpr double kLaplaceSmoothing = 0.1;

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& data);
double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY, std::multimap<int, ImageData>& data);
std::array<std::array<double, 28>, 28> GetPixelProbabilitiesForClass(int imageClass, std::multimap<int, ImageData>& data);
std::array<std::array<std::array<double, 28>, 28>, 10> GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& data);

#endif /* ClassifierTrainer_hpp */
