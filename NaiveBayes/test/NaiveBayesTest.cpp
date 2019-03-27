//
//  NaiveBayesTest.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Classifier.hpp"

std::string trainingLabels = "/Users/mohamedamn/Downloads/digitdata/traininglabels";
std::string trainingImages = "/Users/mohamedamn/Downloads/digitdata/trainingimages";

std::multimap<int, ImageData> trainingData = LoadData(trainingImages, trainingLabels);

TEST_CASE("Maps Input") {
    
    SECTION("Maps Key") {
        CHECK((*trainingData.begin()).first == 0);
    }
    
    SECTION("Maps Value") {
        CHECK((*trainingData.begin()).second.pixelArray[6][13] == 1);
    }
    
}

TEST_CASE("Trains Data") {
    
    std::array<ImageClassProbabilityData, kNumClasses> allProbabilities = GetPixelProbabilitiesAllClasses(trainingData);
    
    CHECK(allProbabilities[1].pixelsProbability[1][0] == 0.00017755681818181819);
    
}

TEST_CASE("Calculates label 75% of the time") {
    
    std::string testImages = "/Users/mohamedamn/Downloads/digitdata/testimages";
    std::string testLabels = "/Users/mohamedamn/Downloads/digitdata/testlabels";
    
    std::multimap<int, ImageData> testData = LoadData(testImages, testLabels);
    
    SaveTrainingModels(std::string("/Users/mohamedamn/Documents/naivebayes-mamn2/NaiveBayes/Data/trainingdata"), testData);
    
    std::array<ImageClassProbabilityData, kNumClasses> allProbabilities = GetPixelProbabilitiesAllClasses(trainingData);
    
    int numWinners = ReportConfusionMatrix(testData, allProbabilities);
    
    CHECK((double) numWinners / 1000 >= .75);
    
}
