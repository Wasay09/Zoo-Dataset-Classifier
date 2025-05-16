#include "givenA1.h"

int main(int argc, char * argv[]){

    // declaring variables
    int fileExist = 0;
    struct Animal dataZoo[NUM_SAMPLES];
    struct Animal testData [NUM_TEST_DATA];
    int choice = 0;
    float ed = 0.0;
    int hd = 0;
    float js = 0.0;
    float * euclideanDistance = &ed;
    int * hammingDistance = &hd;
    float * jaccardSimilarity = &js;
    int vector1[NUM_FEATURES] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    int vector2[NUM_FEATURES] = {1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 4, 0, 0, 1};
    int newSample[NUM_FEATURES] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    int k = 5;
    int whichDistanceFunction = 0;
    int kNearestNeighbors[NUM_SAMPLES];
    int classLabel = 0;
    float accuracy = 0.0;
    int check = 0;

    // giving the menu to user and getting their choice
    printf("Here is the menu - enter a number between 1 and 5\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // while loop to check their choice
    while(choice >= 1 && choice <= 5){
        // calls task1
        if(choice == 1){
            fileExist = readFromFile(argv[1], dataZoo); // passing from the command line

            // if file doesnt exist then print error message and stop the program
            if(fileExist == -1){
                printf("File does not exist\n");
                break;
            }
            // printing out the data
            for(int i = 0; i < NUM_SAMPLES; i++){
                printf("%s ", dataZoo[i].animalName);
                for(int j = 0; j < NUM_FEATURES; j++){
                    printf("%d ", dataZoo[i].features[j]);
                }
                printf("%d ", dataZoo[i].classLabel);
                printf("\n");
            }
            check = 1; // making check = 1
        }
        // calling task2 and printing out distances
        else if(choice == 2){
            // checking if choice 1 has been entered before choice 2 in order to run it otherwise exit the program
            if(check == 1){
                distanceFunctions (vector1, vector2, euclideanDistance, hammingDistance, jaccardSimilarity);
                printf("Eculidean Distance = %f\n", *euclideanDistance);
                printf("Hamming Distance = %d\n", *hammingDistance);
                printf("Jaccard Similarity = %f\n\n", *jaccardSimilarity);
            }
            else{
                break;
            }
        }
        // calling task3
        else if(choice == 3){
            // checking if choice 1 has been entered before choice 3 in order to run it otherwise exit the program
            if(check == 1){
                // for loop for each distance
                for(int i = 1; i <= 3; i++){

                    whichDistanceFunction = i;// setting whichDistanceFunction to i

                    findKNearestNeighbors (dataZoo, newSample, k, whichDistanceFunction, kNearestNeighbors);

                    // depending on which distance function it is, it will print out a message and their nearest neighbors
                    if(whichDistanceFunction == 1){
                        printf("Nearest neighbors for new sample with Euclidean Distance: ");
                        for(int j = 0; j < k; j++){
                            printf("%d ", kNearestNeighbors[j]);
                        }
                        printf("\n");
                    }
                    else if(whichDistanceFunction == 2){
                        printf("Nearest neighbors for new sample with Hamming Distance: ");
                        for(int m = 0; m < k; m++){
                            printf("%d ", kNearestNeighbors[m]);
                        }
                        printf("\n");
                    }
                    else if(whichDistanceFunction == 3){
                        printf("Nearest neighbors for new sample with Jaccard Similarity: ");
                        for(int n = 0; n < k; n++){
                            printf("%d ", kNearestNeighbors[n]);
                        }
                        printf("\n");
                    }
                }
            }
            else{
                break;
            }
        }
        // calling task4
        else if(choice == 4){
            // checking if choice 1 has been entered before choice 4 in order to run it otherwise exit the program
            if(check == 1){
                // for loop to get which distance function
                for(int i = 1; i <= 3; i++){
                    whichDistanceFunction = i;

                    // calling predictClass function
                    classLabel = predictClass (dataZoo, newSample, whichDistanceFunction, k);

                    // printing out the predicted class for each distance function
                    if(whichDistanceFunction == 1){
                        printf("The predicted class is: %d\n", classLabel);
                    }
                    else if(whichDistanceFunction == 2){
                        printf("The predicted class is: %d\n", classLabel);
                    }
                    else if(whichDistanceFunction == 3){
                        printf("The predicted class is: %d\n", classLabel);
                    }
                }
                printf("\n");
            }
            else{
                break;
            }
        }
        // calling task5
        else if(choice == 5){
            // checking if choice 1 has been entered before choice 5 in order to run it otherwise exit the program
            if(check == 1){
                // for loop for each distance function
                for(int i = 1; i <= 3; i++){
                    whichDistanceFunction = i;

                    accuracy = findAccuracy (dataZoo, whichDistanceFunction, testData, k);

                    // printing out each accuracy for each distance
                    if(whichDistanceFunction == 1){
                        printf("The accuracy for the test data is %f\n", accuracy);
                    }
                    else if(whichDistanceFunction == 2){
                        printf("The accuracy for the test data is %f\n", accuracy);
                    }
                    else if(whichDistanceFunction == 3){
                        printf("The accuracy for the test data is %f\n", accuracy);
                    }
                }
            }
            else{
                break;
            }
        }

        // giving the menu again
        printf("Here is the menu - enter a number between 1 and 5\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}