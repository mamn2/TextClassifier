//
//  ClassifierEvaluator.hpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#ifndef ClassifierEvaluator_hpp
#define ClassifierEvaluator_hpp

#include <stdio.h>
#include "InputHandler.hpp"
#include "ClassifierTrainer.hpp"

//Calculates what class the image most likely belongs to
int HighestProbableClassOfImage(ImageData& image,
        std::multimap<int, ImageData>& trainedData, std::array<ImageClassProbabilityData, kNumClasses>& trainedDataProbabilities);

//Calculates the probability that the image belongs to the class
double ProbabilityImageBelongsToClass(int imageClass, ImageData& image,
        ImageClassProbabilityData& trainedDataProbabilities, double probOfClass);

#endif /* ClassifierEvaluator_hpp */
