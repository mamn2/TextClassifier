//
//  ClassifierEvaluator.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "Classifier.hpp"
#include <cmath>
#include <iostream>

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

//Helper function for ReportConfusionMatrix, prints the classification results for each class
inline void printClassificationResults(std::array<int, kNumClasses> probabilityEachClass) {
    
    for (int i = 0; i < probabilityEachClass.size(); i++) {
        std::string toPrint = std::to_string(probabilityEachClass[i]);
        
        for (long start = toPrint.size(); start < 5; start++) {
            toPrint += " ";
        }
        
        std::cout << toPrint;
        
    }
    
}

int ReportConfusionMatrix(std::multimap<int, ImageData>& testData,
                          std::array<ImageClassProbabilityData, kNumClasses>& allProbabilities) {

    int numCorrect = 0;
    int numWrong = 0;

    std::cout << "   C0   C1   C2   C3   C4   C5   C6   C7   C8   C9" << std::endl;

    int currentLabel = 0;
    std::cout << "C" << currentLabel << " ";

    std::array<int, kNumClasses> probabilityEachClass;
    probabilityEachClass.fill(0);

    for (auto itr = testData.begin(); itr != testData.end(); ++itr) {
    
        if ((*itr).first != currentLabel) {
        
            printClassificationResults(probabilityEachClass);
            probabilityEachClass.fill(0);
            currentLabel = (*itr).first;
            std::cout << "\nC" << currentLabel << " ";
        }
    
        probabilityEachClass[HighestProbableClassOfImage((*itr).second, testData, allProbabilities)]++;
    
        if (HighestProbableClassOfImage((*itr).second, testData, allProbabilities) == (*itr).first) {
            numCorrect++;
        } else {
            numWrong++;
        }
    
        if (++itr == testData.end()) {
            printClassificationResults(probabilityEachClass);
            break;
        } else {
            itr--;
        }
    
    }
    
    return numCorrect;

}
