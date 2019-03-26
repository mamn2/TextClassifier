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

constexpr double kLaplaceSmoothing = 4.0;

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& data);
double ProbabilityOfFeatureGivenClass(int imageClass, int feature, int pixelArrayX, int pixelArrayY, std::multimap<int, ImageData> data);
double ProbabilityImageBelongsToClass(int imageClass, ImageData image, std::multimap<int, ImageData> data);
long HighestProbableClassOfImage(ImageData image, std::multimap<int, ImageData> data);
std::vector<std::vector<double>> GetFeatureProbabilities(std::multimap<int, ImageData image>> data, int feature)

#endif /* ClassifierTrainer_hpp */
