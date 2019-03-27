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
//    std::multimap<int, ImageData> data = LoadData(trainingImages, trainingLabels);
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
//    std::array<ImageClassProbabilityData, kNumClasses> allProbabilities = GetPixelProbabilitiesAllClasses(data);
//    
//    int numCorrect = 0;
//    int numWrong = 0;
//    
//    for (auto itr = testData.begin(); itr != testData.end(); ++itr) {
//        if (HighestProbableClassOfImage((*itr).second, testData, allProbabilities) == (*itr).first) {
//            numCorrect++;
//        } else {
//            numWrong++;
//        }
//    }
//    
//    std::cout << "Number of correct classifications: " << numCorrect << std::endl;
//    std::cout << "Number of incorrect classifications " << numWrong << std::endl;
//    
//}
//
////training labels: /Users/mohamedamn/Downloads/digitdata/traininglabels
////training images: /Users/mohamedamn/Downloads/digitdata/trainingimages
//
////test labels = /Users/mohamedamn/Downloads/digitdata/teslabels
////test images = /Users/mohamedamn/Downloads/digitdata/testimages
//
