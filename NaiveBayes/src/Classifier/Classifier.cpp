//
//  ClassifierEvaluator.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "Classifier.hpp"
#include <cmath>

int HighestProbableClassOfImage(ImageData& image, std::multimap<int, ImageData>& trainedData,
                            std::array<ImageClassProbabilityData, kNumClasses>& trainedDataProbabilities) {
    
    double highestProbability = ProbabilityImageBelongsToClass(0, image, trainedDataProbabilities[0],
                                                               ProbabilityOfClass(0, trainedData));
    int mostLikelyClass = 0;
    
    for (int i = 1; i < kNumClasses; i++) {
        double currentProb = ProbabilityImageBelongsToClass(i, image, trainedDataProbabilities[i], ProbabilityOfClass(i, trainedData));
        if (currentProb > highestProbability) {
            highestProbability = currentProb;
            mostLikelyClass = i;
        }
    }
    
    return mostLikelyClass;
    
}

double ProbabilityImageBelongsToClass(int imageClass, ImageData& image,
                                    ImageClassProbabilityData& trainedDataProbabilities, double probOfClass) {
    
    double probability = log(probOfClass);
    
    for (int i = 0; i < image.pixelArray.size(); i++) {
        for (int j = 0; j < image.pixelArray.size(); j++) {
            if (image.pixelArray[i][j] == 1) {
                probability += log(trainedDataProbabilities.pixelsProbability[i][j]);
            } else {
                probability += log(1.0 - trainedDataProbabilities.pixelsProbability[i][j]);
            }
        }
    }
    
    return probability;
    
}
