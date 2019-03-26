//
//  InputHandler.hpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>
#include <array>
#include <map>

constexpr int kImageSideLength = 28;

enum PixelType { WHITE = 0, BLACK = 1, GREY = 1 };

struct ImageData {
    
    std::array<std::array<int, kImageSideLength>, kImageSideLength> pixelArray;
    
};

// Loads image data from file. Returns a map associating each number with a set of example images
std::multimap<int, ImageData> LoadData(std::string& imagesFile, std::string& labelsFile);

#endif /* InputHandler_hpp */
