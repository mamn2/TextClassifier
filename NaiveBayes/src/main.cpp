////
////  main.cpp
////  NaiveBayes
////
////  Created by Mohamed Amn on 3/19/19.
////  Copyright © 2019 Mohamed Amn. All rights reserved.
////
//
//
//
//#include <iostream>
//#include "Classifier.hpp"
//
//int main(int argc, const char * argv[]) {
//    
//    std::string trainingLabels;
//    std::cout << "Enter the filepath of the training labels: ";
//    std::cin >> trainingLabels;
//    
//    std::string trainingImages;
//    std::cout << "Enter the filepath of the training images: ";
//    std::cin >> trainingImages;
//    
//    std::multimap<int, ImageData> trainingData = LoadData(trainingImages, trainingLabels);
//    
//    std::string testLabels;
//    std::cout << "Enter the filepath of the labels you want to test: ";
//    std::cin >> testLabels;
//    
//    std::string testImages;
//    std::cout << "Enter the filepath of the images you want to test: ";
//    std::cin >> testImages;
//    
//    
//    std::multimap<int, ImageData> testData = LoadData(testImages, testLabels);
//    
//    std::string filepath;
//    std::cout << "Do you want to print the training data? If yes, type filepath, otherwise hit enter" << std::endl;
//    std::cin >> filepath;
//    if (!filepath.empty()) {
//        SaveTrainingModels(filepath, trainingData);
//    }
//    
//    std::array<ImageClassProbabilityData, kNumClasses> allProbabilities = GetPixelProbabilitiesAllClasses(trainingData);
//    
//    int numCorrect = ReportConfusionMatrix(testData, allProbabilities);
//    
//    std::cout << "\nNumber of correct classifications: " << numCorrect << std::endl;
//    std::cout << "Number of incorrect classifications " << 1000 - numCorrect << std::endl;
//    
//}
//
////training labels: /Users/mohamedamn/Downloads/digitdata/traininglabels
////training images: /Users/mohamedamn/Downloads/digitdata/trainingimages
//
////test labels = /Users/mohamedamn/Downloads/digitdata/testlabels
////test images = /Users/mohamedamn/Downloads/digitdata/testimages
//
////training data = /Users/mohamedamn/Documents/naivebayes-mamn2/NaiveBayes/Data/trainingdata
//
