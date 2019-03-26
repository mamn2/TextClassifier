//
//  ClassifierTrainer.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "ClassifierTrainer.hpp"

double ProbabilityOfFeatureGivenClass(int imageClass, int feature, int pixelArrayX, int pixelArrayY, std::multimap<int, ImageData> data) {
    
    auto lowerBoundItr = data.lower_bound(imageClass);
    auto upperBoundItr = data.upper_bound(imageClass);
    
    int numClassWithFeature = 0;
    int numClass = 0;
    
    while (lowerBoundItr != upperBoundItr) {
        if (lowerBoundItr -> first == imageClass) {
            if (lowerBoundItr -> second.pixelArray[pixelArrayX][pixelArrayY] == feature) {
                numClassWithFeature++;
            }
            numClass++;
        }
        lowerBoundItr++;
    }
    
    double probablityOfFeatureGivenClass = (kLaplaceSmoothing + numClassWithFeature) / (2 * kLaplaceSmoothing + numClass);
    
    return probablityOfFeatureGivenClass;
    
}
