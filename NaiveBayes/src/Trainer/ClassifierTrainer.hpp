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

//contains the feature probability data for each class (0, 1, ..., 9)
struct ImageClassProbabilityData {
    std::array<std::array<double, kImageSideLength>, kImageSideLength> pixelsProbability;
};

//calculates the probability of this class occuring in the training data
double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& trainingData);

//calculates the probability a feature in an image given an image class
double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY,
                                      std::multimap<int, ImageData>& trainingData);

//Gets all the pixel probabilities for a single class
ImageClassProbabilityData GetPixelProbabilitiesForClass(int imageClass, std::multimap<int, ImageData>& trainingData);

//Gets all the pixel probability data for all classes
std::array<ImageClassProbabilityData, kNumClasses> GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& trainingData);

#endif /* ClassifierTrainer_hpp */
