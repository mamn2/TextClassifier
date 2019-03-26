//
//  ClassifierTrainer.hpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#ifndef ClassifierTrainer_hpp
#define ClassifierTrainer_hpp

#pragma once

#include <stdio.h>
#include <array>
#include <map>
#include "InputHandler.hpp"

constexpr double kLaplaceSmoothing = 4.0;

double ProbabilityOfFeatureGivenClass(int imageClass, int feature, int pixelArrayX, int pixelArrayY, std::multimap<int, ImageData> data);


#endif /* ClassifierTrainer_hpp */
