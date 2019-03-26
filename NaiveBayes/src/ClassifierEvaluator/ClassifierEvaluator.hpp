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

int HighestProbableClassOfImage(ImageData& image,
        std::multimap<int, ImageData>& data, std::array<std::array<std::array<double, 28>, 28>, 10>& probabilites);
double ProbabilityImageBelongsToClass(int imageClass, ImageData& image,
        std::array<std::array<double, 28>, 28>& probabilities, double probOfClass);

#endif /* ClassifierEvaluator_hpp */
