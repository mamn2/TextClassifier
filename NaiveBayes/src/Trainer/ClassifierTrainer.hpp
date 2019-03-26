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
constexpr int kNumClasses = 10;

struct ImageClassProbabilityData {
    std::array<std::array<double, kImageSideLength>, kImageSideLength> PixelsProbability;
};

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& trainingData);

double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY,
                                      std::multimap<int, ImageData>& trainingData);

std::array<std::array<double, kImageSideLength>, kImageSideLength> GetPixelProbabilitiesForClass(int imageClass,
                                                                                std::multimap<int, ImageData>& data);

std::array<std::array<std::array<double, kImageSideLength>, kImageSideLength>, kNumClasses>
    GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& data);

#endif /* ClassifierTrainer_hpp */
