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
    // Temporal holder for the img bytes
    RGBTRIPLE tmp[height][width];

    // Iterate over the rows
    for (int row = 0; row < height; row++)
    {
        // Iterate over the columns
        for (int col = 0; col < width; col++)
        {
            // copy the img byte values to tmp
            tmp[row][col] = image[row][col];
        }
    }

    // Iterate over the rows
    for (int row = 0; row < height; row++)
    {
        // declare variables to be used for avg and count
        float red, green, blue, count;

        // Iterate over the columns
        for (int col = 0; col < width; col++)
        {

            // Initialize the varibles to 0 in every column
            red =  green = blue = count = 0.0;

            // Check if their are surrounding pixels
            for (int updown = -1; updown < 2; updown ++)
            {
                for (int leftright = -1; leftright < 2; leftright++)
                {
                    if (row + updown < 0 || row + updown >= height)
                    {
                        continue;
                    }

                    if (col + leftright < 0 || col + leftright >= width)
                    {
                        continue;
                    }

                    // Collect values of different color bytes
                    red += tmp[row + updown][col + leftright].rgbtRed;
                    green += tmp[row + updown][col + leftright].rgbtGreen;
                    blue += tmp[row + updown][col + leftright].rgbtBlue;
                    count++;
                }
            }

            // Set the average value to the pixel
            image[row][col].rgbtRed = round(red / count);
            image[row][col].rgbtGreen = round(green / count);
            image[row][col].rgbtBlue = round(blue / count);
        }
    }
    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
