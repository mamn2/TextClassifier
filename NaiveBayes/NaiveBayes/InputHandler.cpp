//
//  InputHandler.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "InputHandler.hpp"
#include <fstream>

std::multimap<int, std::array<std::array<int, imageSideLength>, imageSideLength>> LoadData(std::string& imagesFile, std::string& labelsFile) {
    
    std::ifstream imagesFileStream;
    imagesFileStream.open(imagesFile);
    
    std::ifstream labelsFileStream;
    labelsFileStream.open(labelsFile);
    
    std::string label;
    
    std::multimap<int, std::array<std::array<int, imageSideLength>, imageSideLength>> mappedImageData;
    
    //Goes through each line in the traininglabels file and matches it with data in the trainingimages file
    while (getline(labelsFileStream, label)) {
        int integerLabel = std::stoi(label);
        
        std::array<std::array<int, imageSideLength>, imageSideLength> image;
        
        //Adds each character to the 2d array representing the given image
        for (int i = 0; i < imageSideLength; i++) {
            for (int j = 0; j < imageSideLength + 1; j++) {
                char pixel;
                imagesFileStream.get(pixel);
                if (pixel == '\n') {
                    continue;
                } else if (pixel == '#') {
                    image[i][j] = 1;
                } else if (pixel == '+') {
                    image[i][j] = 1;
                } else {
                    image[i][j] = 0;
                }
            }
        }
        mappedImageData.insert({integerLabel, image});
    }
    
    return mappedImageData;
    
}
