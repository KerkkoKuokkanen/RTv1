# RTv1

## Summary

A simple ray tracing program made in C and SDL that simulates light, shadows and simple objects. All the code can be found in this repository and compiles on macOS, but not on m1 because the SDL framework is not updated.

Program goes through the screen pixel by pixel and looks if there is a part of an object there that is visible from camera. After that the program checks if the light can reach that point without any obstacles and gives that point some color.

All of the input comes from a textfile and these example scenes can be found in the repository. You can add as many objects to the files and move and rotate them around. Camera can also be moved and rotated.

#### All of the simple objects in the same scene

<img width="995" alt="Screen Shot 2023-01-11 at 4 49 37 PM" src="https://user-images.githubusercontent.com/93378894/211837899-f58f7387-199b-431e-8f96-b7cd18bcdbb3.png">

#### Sphere in front of plane

<img width="835" alt="Screen Shot 2023-01-11 at 4 50 44 PM" src="https://user-images.githubusercontent.com/93378894/211837932-1d4b8e45-e494-41d5-a744-833cea9b0200.png">

<img width="992" alt="Screen Shot 2023-01-11 at 4 49 53 PM" src="https://user-images.githubusercontent.com/93378894/211837959-e303b228-ca6a-4206-b771-b5e55260f7d4.png">

<img width="895" alt="Screen Shot 2023-01-11 at 4 50 23 PM" src="https://user-images.githubusercontent.com/93378894/211837974-e8c7a961-258a-48a3-84b9-ca24e9efd448.png">
