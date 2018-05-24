/**
 * Roll n-sided dice 3 times. (i, j, k).
 * Does (i, j, k) meet Triangle inequality?
 * Determine the probability.
 */

#include <iostream>
using namespace std;

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define max3(a, b, c) (max2((a), max2((b), (c))))

#define combi2(a, b) ((a) == (b) ? 1 : 2)
#define combi3(a, b, c) ((a) == (b) ? ((b) == (c) ? 1 : 3) : ((b) == (c) ? 3 : ((a) == (c) ? 3 : 6)))

int main_n_cubic(){
	for(int dice_size = 1; dice_size <= 1000; dice_size++){

		int denominator = dice_size * dice_size * dice_size;
		int numerator = 0;
		for(int dice1 = 1; dice1 <= dice_size; dice1++){
			for(int dice2 = 1; dice2 <= dice_size; dice2++){
				for(int dice3 = 1; dice3 <= dice_size; dice3++){
					//cout << dice1 << "," << dice2 << "," << dice3 << endl;
					/**
					 * a + b     > c     (c is max)
					 * <=>
					 * a + b + c > c + c
					 */
					if(dice1 + dice2 + dice3 > 2 * max3(dice1, dice2, dice3)){
						numerator ++;
					}
				}

			}
		}

		cout << dice_size << "-sided dice : " << numerator << "/" << denominator << "="
			 << (double)numerator / denominator << endl;

	}
}

int main_n_cubic_pruned(){
	for(int dice_size = 1; dice_size <= 1000; dice_size++){

		int denominator = dice_size * dice_size * dice_size;
		int numerator = 0;
		for(int dice1 = 1; dice1 <= dice_size; dice1++){
			for(int dice2 = dice1; dice2 <= dice_size; dice2++){
				for(int dice3 = dice2; dice3 <= dice_size; dice3++){
					//cout << dice1 << "," << dice2 << "," << dice3 << " : " << ((dice1 + dice2 > dice3) ? combi(dice1, dice2, dice3) : 0) << endl;
					if(dice1 + dice2 > dice3){
						numerator += combi3(dice1, dice2, dice3);
					}
				}
			}
		}

		cout << dice_size << "-sided dice : " << numerator << "/" << denominator << "="
			 << (double)numerator / denominator << endl;
	}
}

/**
 * Use data of n-1 when calc n.
 * Calc only (n, [1, n], [1, n]) in each n.
 */
int main_n_square(){
	long long denominator;
	long long numerator = 0;
	for(long long dice_size = 1; dice_size <= 1000; dice_size++){
		denominator = dice_size * dice_size * dice_size;
		long long dice1, dice2, dice3;

		dice1 = dice_size; // critical
		for(dice2 = 1; dice2 <= dice_size; dice2++){
			for(dice3 = dice2; dice3 <= dice_size; dice3++){
				//cout << dice1 << "," << dice2 << "," << dice3 << " : " << ((dice1 + dice2 > dice3) ? combi3(dice1, dice2, dice3) : 0) << endl;
				if(dice1 + dice2 + dice3 > 2 * max3(dice1, dice2, dice3)){
					numerator += combi3(dice1, dice2, dice3);
				}
			}
		}

		cout << dice_size << "-sided dice : " << numerator << "/" << denominator << "="
			 << (double)numerator / denominator << endl;
	}
}

/**
 * I get general polynomial.
 *
 * numerator   = (dice_size ^ 3 + dice_size) / 2
 * denominator = dice_size ^ 3
 * probability = 1 / 2 + 1 / (2 * dice_size ^ 2)
 */
int main(){
	for(long long dice_size = 1; dice_size <= 1000; dice_size++){
		long long denominator = dice_size * dice_size * dice_size;
		long long numerator = dice_size * dice_size * dice_size / 2 + dice_size / 2;
		cout << dice_size << "-sided dice : " << numerator << "/" << denominator << "="
			 << (double)numerator / denominator << endl;
	}
}

