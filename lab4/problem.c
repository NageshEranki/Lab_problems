#include <stdio.h>


void print(float* matrix, int rows, int cols)
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("%f ", *((matrix+i*cols)+j));
    }
    printf("\n");
  }
  printf("\n");
}


void transpose(float* transpose, float* matrix, int rows, int cols)
{
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      *((transpose + i*cols) + j) = *((matrix + j*cols) + i);
    }
  }
}


int symmetric(float* matrix, int rows, int cols)
{
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      if( *((matrix + i*cols)+j) != *((matrix + j*cols)+i))
      {
        return 0;
      }
    }
  }
  return 1;
}


int main()
{
  int rows,cols;
  printf("Enter the number of rows:\n");
  scanf("%d", &rows);
  printf("Enter the number of cols:\n");
  scanf("%d", &cols);

  float matrix[rows][cols];
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("Enter the value @: %d,%d: \n",i,j);
      scanf("%f",&matrix[i][j]);
    }
  }
  print(matrix,rows,cols);

  float tr[rows][cols];
  transpose(tr,matrix,rows,cols);
  print(tr,rows,cols);
  printf("Symmetry of matrix: %d\n", symmetric(matrix,rows,cols));
  return 0;
}
