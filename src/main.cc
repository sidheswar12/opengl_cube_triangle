
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "cube.h"
#include "triangle.h"
#include "rotatecube.h"
#include "readImage.h"
#include "listDirectory.h"

#include <IL/il.h>

using namespace std;


int main(int argc, char **argv)
{
        if( argc!=3)
        {
                cout<<"Usage: Please provide all below arguments"<<endl;
                cout<<"Provide parameter i/p_file_path, o/p_file_path"<<endl;                 
                return -1;
        }
        string inPath = argv[1];
        string outPath = argv[2];

        vector<string> fileList;
        listFiles(inPath, &fileList);

        IplImage *pImg;        
        for(auto fileName:fileList)
        {       
                string filePath = inPath+"/"+fileName;
                pImg = readImages(filePath);
                
                saveImage(pImg, outPath+"/"+fileName);
        }        
        return 0;
}

void drawShapes(int argc, char **argv)
{
        string str = argv[3];
        glutInit(&argc, argv);        
        
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

        glutInitWindowSize(700,700);
        glutInitWindowPosition(100, 100);

        if(str == "C")
        {
                glutCreateWindow("Cube");
                glEnable(GL_DEPTH_TEST);
                glutDisplayFunc(drawCube);
                glutSpecialFunc(keyboard);
        }  
        if(str == "T")
        {
                glutInitDisplayMode(GLUT_SINGLE);
                glutCreateWindow("Triangle");
                glutDisplayFunc(drawTriangle);
        }
        if(str == "R")
        {
                glutCreateWindow("Rotating a Cube");
                initRendering();
                glutDisplayFunc(drawCube3D);
                glutReshapeFunc(handleResize);        
                glutTimerFunc(25, update, 0);
        }
        glutMainLoop();
}

