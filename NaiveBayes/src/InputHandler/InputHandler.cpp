//
//  InputHandler.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "InputHandler.hpp"
#include <fstream>

std::multimap<int, ImageData> LoadData(std::string& imagesFile, std::string& labelsFile) {
    
    std::ifstream imagesFileStream;
    imagesFileStream.open(imagesFile);
    
    std::ifstream labelsFileStream;
    labelsFileStream.open(labelsFile);
    
    std::multimap<int, ImageData> mappedImagesData;
    
    std::string imageLabel;
    
    //Goes through each line in the traininglabels file and matches it with data in the trainingimages file
    while (getline(labelsFileStream, imageLabel)) {
        int imageLabelInt = std::stoi(imageLabel);
        
        ImageData currentImage;
        
        //Adds each character to the 2d array representing the given image
        for (int i = 0; i < kImageSideLength; i++) {
            for (int j = 0; j < kImageSideLength + 1; j++) {
                char pixelValue;
                imagesFileStream.get(pixelValue);
                
                //Gives gray and black pixels a value of 1 and white pixels a value of 0
                if (pixelValue == '\n') {
                    continue;
                } else if (pixelValue == '#') {
                    currentImage.pixelArray[i][j] = BLACK;
                } else if (pixelValue == '+') {
                    currentImage.pixelArray[i][j] = GREY;
                } else {
                    currentImage.pixelArray[i][j] = WHITE;
                }
            }
        }
        
        mappedImagesData.insert( { imageLabelInt, currentImage } );
    }
    
    return mappedImagesData;
    
}
