#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 1
#define UP 2
#define DOWN 3
#define RIGHT 4

#define SIZE 4

void print_box(int *box,int score);
void move(int *box,int side,int *score);
int update_box(int *box);

void main() {
    char input;
    int *box,i,score=0;

    srand(time(NULL));

    box=(int *)malloc(SIZE*SIZE*sizeof(int));
    if( box == NULL )                      /*Check for failure. */
    {
       printf( "Can't allocate memory!" );
       exit( 0 );
    }

    for(i=0;i<SIZE*SIZE;i++)        //Initializing to 0
        *(box+i)=0;


    while(update_box(box)) {


            print_box(box,score);

            do
            {
                input = getchar();
            }while ( input == '\n' || input == EOF);

            switch(input)
            {
            case 'w':
                move(box,UP,&score);
                break;
            case 'a':
                move(box,LEFT,&score);
                break;
            case 's':
                move(box,DOWN,&score);
                break;
            case 'd':
                move(box,RIGHT,&score);
                break;
            case 'e':
                printf("Exiting the program -\n");
                exit(1);
            default:
                printf("Invalid entry. \n");
            }

    }


    free(box);
}


void print_box(int *box,int score) {
    int i,r,c;

    for(i=0;i<(24-2*SIZE)/2-1;i++)
        printf("\n");

    for(r=0;r<SIZE;r++) {
        for(c=0;c<SIZE;c++) {
            printf("\t|\t%4d",*(box+SIZE*r+c));
        }
        printf("\t|\n\n");
    }

    printf("\t\t SCORE : %d \n",score);

    for(i=0;i<(24-2*SIZE)/2;i++)
        printf("\n");
}

int update_box(int *box) {
    int free[16],n=0,i;

    //Parsing through to find free space
    for(i=0;i<SIZE*SIZE;i++) {
        if(*(box+i)==0) {
            free[n++]=i;
        }
    }

    if(n==0) {
        printf("Game Over! \n");
        return 0;
    }

    else {
        *(box+free[rand()%n])=2*(rand()%2+1);       //Assigns 2 or 4 to random free space
        return 1;
    }
}

void move(int *box,int side,int *score) {
    int p,r,c,k,l;

    if(side==LEFT) {
        for( r=0 ; r<SIZE ; r++ ) {
            for( c=0 ; c<SIZE ; c++ ) {

                p=c;

                for( k=c ; k<SIZE ; k++ ) {
                        if( *(box+SIZE*r+k)!=0 ) {
                            p=k;

                            for( l=k+1 ; l<SIZE ; l++ ) {
                                if( *(box+SIZE*r+l) != 0 ) {            //Checking if it can add up with the next coming number
                                    if(*(box+SIZE*r+k)==*(box+SIZE*r+l)) {
                                        *score+=*(box+SIZE*r+k);
                                        *(box+SIZE*r+k)*=2;
                                        *(box+SIZE*r+l)=0;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                }
                if(p!=c) {
                    *(box+SIZE*r+c)=*(box+SIZE*r+p);
                    *(box+SIZE*r+p)=0;
                }
            }
        }
    }

    else if(side==UP) {
        for( c=0 ; c<SIZE ; c++ ) {
            for( r=0 ; r<SIZE ; r++ ) {

                p=r;

                for( k=r ; k<SIZE ; k++ ) {
                        if( *(box+SIZE*k+c)!=0 ) {
                            p=k;

                            for( l=k+1 ; l<SIZE ; l++ ) {
                                if( *(box+SIZE*l+c) != 0 ) {            //Checking if it can add up with the next coming number
                                    if(*(box+SIZE*k+c)==*(box+SIZE*l+c)) {
                                        *score+=*(box+SIZE*k+c);
                                        *(box+SIZE*k+c)*=2;
                                        *(box+SIZE*l+c)=0;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                }
                if(p!=r) {
                    *(box+SIZE*r+c)=*(box+SIZE*p+c);
                    *(box+SIZE*p+c)=0;
                }
            }
        }
    }

    else if(side==DOWN) {
        for( c=0 ; c<SIZE ; c++ ) {
            for( r=SIZE-1 ; r>=0 ; r-- ) {

                p=r;

                for( k=r ; k>=0 ; k-- ) {
                        if( *(box+SIZE*k+c)!=0 ) {
                            p=k;

                            for( l=k-1 ; l>=0 ; l-- ) {
                                if( *(box+SIZE*l+c) != 0 ) {            //Checking if it can add up with the next coming number
                                    if(*(box+SIZE*k+c)==*(box+SIZE*l+c)) {
                                        *score+=*(box+SIZE*k+c);
                                        *(box+SIZE*k+c)*=2;
                                        *(box+SIZE*l+c)=0;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                }
                if(p!=r) {
                    *(box+SIZE*r+c)=*(box+SIZE*p+c);
                    *(box+SIZE*p+c)=0;
                }
            }
        }
    }

    else if(side==RIGHT) {
        for( r=0 ; r<SIZE ; r++ ) {
            for( c=SIZE-1 ; c>=0 ; c-- ) {

                p=c;

                for( k=c ; k>=0 ; k-- ) {
                        if( *(box+SIZE*r+k)!=0 ) {
                            p=k;

                            for( l=k-1 ; l>=0 ; l-- ) {
                                if( *(box+SIZE*r+l) != 0 ) {            //Checking if it can add up with the next coming number
                                    if(*(box+SIZE*r+k)==*(box+SIZE*r+l)) {
                                        *score+=*(box+SIZE*r+k);
                                        *(box+SIZE*r+k)*=2;
                                        *(box+SIZE*r+l)=0;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                }
                if(p!=c) {
                    *(box+SIZE*r+c)=*(box+SIZE*r+p);
                    *(box+SIZE*r+p)=0;
                }
            }
        }
    }

}
