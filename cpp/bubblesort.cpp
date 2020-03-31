#include <iostream>

int main ()
{
  //Array initialisieren
  int parkkarten_ids[] = {5,13,2,18,4,11,1,19,0,9,17,3,12,14,6,7,15,8,10,16};
  
  //Alternative Initialiserungen für Tests
  //int parkkarten_ids[] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  //int parkkarten_ids[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  //int parkkarten_ids[] = {1000,0,250,100,10,5,5,10,1,10,0,1000,0};
  
  int array_laenge = (sizeof (parkkarten_ids) / sizeof (int));
  bool sorted = false;
  int tmp, iterations = 0;


  //HIER bitte Ihren Sortieralgorithmus implementieren
  while (!sorted) {
      iterations++;
      sorted = true;
      for (int i = 0; i < array_laenge - 1; i++) {
          if (parkkarten_ids[i] > parkkarten_ids[i+1]) {
              tmp = parkkarten_ids[i];
              parkkarten_ids[i] = parkkarten_ids[i+1];
              parkkarten_ids[i+1] = tmp;
              sorted = false;
          }
      }
  }
  
  std::cout << "Ausgegebene Parkkarten-IDs:\n";
    for (int i = 0; i < array_laenge; i++) std::cout << parkkarten_ids[i] << " ";
  std::cout << "\n";
  std::cout << "Iterations: " << iterations << std::endl;

  return 0;
}
