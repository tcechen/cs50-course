#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (int) round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0); // calculate average of rgb value
            // assign same value to rgb value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_r;
    int temp_g;
    int temp_b;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_r = (int) round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            temp_g = (int) round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            temp_b = (int) round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (temp_r > 255)
            {
                temp_r = 255;
            }
            if (temp_g > 255)
            {
                temp_g = 255;
            }
            if (temp_b > 255)
            {
                temp_b = 255;
            }
            image[i][j].rgbtRed = temp_r;
            image[i][j].rgbtGreen = temp_g;
            image[i][j].rgbtBlue = temp_b;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int l = 0;
    int r = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j]; // declare temp as RGBTRIPLE data type
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // define a copy of image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    double count; // define as double data type calculate average value of the box blur
    int l = 0;
    int r = 0;
    int red;
    int blue;
    int green;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // define left(l) and right(r) to calculate the box blur value
            red = 0;
            blue = 0;
            green = 0;
            count = 0;
            l = i - 1; // initailize l equal to i - 1
            while (l <= i + 1)
            {
                r = j - 1; // initailize r equal to j - 1
                while (r <= j + 1)
                {
                    if (l >= 0 && r >= 0 && l <= (height - 1) && r <= (width - 1)) // check if l and r is in the image boundary
                    {
                        red += temp[l][r].rgbtRed;
                        blue += temp[l][r].rgbtBlue;
                        green += temp[l][r].rgbtGreen;
                        count = count + 1;
                    }
                    r++;
                }
                l++;
            }
            image[i][j].rgbtRed = (int) round(red / count);
            image[i][j].rgbtGreen = (int) round(green / count);
            image[i][j].rgbtBlue = (int) round(blue / count);
        }
    }
    return;
}
