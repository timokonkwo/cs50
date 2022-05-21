#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int trackAvg = 0;
            trackAvg += image[row][col].rgbtRed;
            trackAvg += image[row][col].rgbtGreen;
            trackAvg += image[row][col].rgbtBlue;

            int newValue = round(trackAvg/3);

            image[row][col].rgbtRed = newValue;
            image[row][col].rgbtGreen = newValue;
            image[row][col].rgbtBlue = newValue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width/2; col++)
        {   
            RGBTRIPLE tmp[width][height];

            tmp[row][col]= image[row][col];
            image[row][col] = image[row][width - col];
            image[row][width - col] = tmp[row][col];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
