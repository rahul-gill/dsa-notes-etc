#include <bits/stdc++.h>
using namespace std;


int digits_in_num(long long num){
	int count = 0;
	while(num > 0){
		++count;
		num /= 10;
	}
	return count;
}

void pattern_square(int lines){
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines; ++j){
			cout<<"*";
		}
		cout<<"\n";
	}
}



void pattern_triangle(int lines){
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<"*";
		}
		cout<<"\n";
	}
}

void pattern_triangle_nums(int lines){
	int num_w = digits_in_num(lines)+1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<setw(num_w)<<j+1;
		}
		cout<<"\n";
	}
}

void pattern_triangle_nums2(int lines){
	int num_w = digits_in_num(lines)+1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<setw(num_w)<<i+1;
		}
		cout<<"\n";
	}
}

void pattern_triangle_reverse(int lines){
	int num_w = digits_in_num(lines)+1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines-i; ++j){
			cout<<setw(num_w)<<j+1;
		}
		cout<<"\n";
	}
}


void pattern_triangle_center(int lines){
	int h_width = 2 * lines - 1;
	int half = h_width/2;
	//first line indexes of stars: half
	//second line indexes of stars: half-1, half, half+1
	//third line indexes of stars: half-2, .. , half-3
	for(int i=0; i<lines; ++i){
		for(int j=0; j<h_width; ++j){
			if(j >= half - i && j <= half + i){
				cout<<"*";
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}


void pattern_triangle_center_reverse(int lines){
	int h_width = 2 * lines - 1;
	int half = h_width/2;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<h_width; ++j){
			int k = lines-1-i;
			//just reverse the i value from pattern_triangle_center method
			if(j >= half - k && j <= half + k){
				cout<<"*";
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}



void pattern_triangle_from_side(int lines){
	int half;
	if(lines % 2 == 1){
		half = lines/2;
	} else {
		half = lines/2 - 1;
	}
	for(int i=0; i<lines; ++i){
		int stars_to_print;
		if(i <= half){
			stars_to_print = i + 1; 
		} else {
			stars_to_print = lines - i;
		}
		for(int j=0; j<stars_to_print; ++j){
			cout<<"*";
		}
		cout<<"\n";
	}
}

void pattern_triangle_01(int lines){
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			if((i+j)%2 == 0){
				cout<<"1";
			} else {
				cout<<"0";
			}
		}
		cout<<"\n";
	}
}

void pattern_v_like_with_numbers(int lines){
	int w_num = digits_in_num(lines)+1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines*2; ++j){
			if(j<=i){
				cout<<setw(w_num)<<j+1;
			} else if(2*lines-i-1>j){
				for(int it = 0; it<w_num; ++it) cout<<" ";
			} else {
				cout<<setw(w_num)<<2*lines-j;
			}
		}
		cout<<"\n";
	}
}

void natural_numbers_in_triangle(int lines){
	int num = 1;
	int wnum = digits_in_num((long long)lines * lines /2 ) + 1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<setw(wnum)<<num;
			num++;
		}
		cout<<"\n";
	}
}



void pattern_triangle_abcd(int lines){
	if(lines > 25){
		return;
	}
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<(char)('A'+j);
		}
		cout<<"\n";
	}
}


void pattern_triangle_abcd_reverse(int lines){
	if(lines > 25){
		return;
	}
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines-i; ++j){
			cout<<(char)('A'+j);
		}
		cout<<"\n";
	}
}


void pattern_triangle_abcd_colwise(int lines){
	if(lines > 25){
		return;
	}
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<(char)('A'+i);
		}
		cout<<"\n";
	}
}

void pattern_triangle_abcd_fromlast(int lines){
	if(lines > 25){
		return;
	}
	for(int i=0; i<lines; ++i){
		for(int j=0; j<i+1; ++j){
			cout<<(char)('A'+lines-1+j-i);
		}
		cout<<"\n";
	}
}
void pattern_triangle_center_abcd(int lines){
	int h_width = 2 * lines - 1;
	int half = h_width/2;
	for(int i=0; i<lines; ++i){
		int startx = half-i, endx = half+i;
		for(int j=0; j<h_width; ++j){
			if(j >= startx && j <= endx){
				int startx_diff = j-startx;
				int endx_diff = endx-j; 
				if(startx_diff <= endx_diff){
					cout<<(char)('A'+startx_diff);
				} else {
					cout<<(char)('A'+endx_diff);
				}
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}



void pattern_quadrilateral_center(int lines){
	int hwidth = lines;
	if(lines % 2 == 0){
		hwidth = lines-1;
	}
	for(int i=0; i<lines; ++i){
		int star_w = (i < lines/2) ?  (2 * i + 1) : (2 * (lines-i) - 1);
		int margins = (hwidth-star_w)/2;

		for(int j=0; j<margins; ++j){
			cout<<" ";
		}
		for(int j=0; j<star_w; ++j){
			cout<<"*";	
		}
		for(int j=0; j<margins; ++j){
			cout<<" ";
		}
		cout<<"\n";
	}
}

void pattern_quadrilateral_invert_1(int lines){
	int hwidth = lines;
	if(lines % 2 == 1){
		hwidth = lines+1;
	}
	for(int i=0; i<lines; ++i){
		int star_w = (i < lines/2) ?  (2 * i ) : (2 * (lines-i) - 2);
		int margins = (hwidth-star_w)/2;

		for(int j=0; j<margins; ++j){
			cout<<"*";
		}
		for(int j=0; j<star_w; ++j){
			cout<<" ";	
		}
		for(int j=0; j<margins; ++j){
			cout<<"*";
		}
		cout<<"\n";
	}
}

void pattern_quadrilateral_invert_2(int lines){
	int hwidth = lines;
	if(lines % 2 == 1){
		hwidth = lines+1;
	}
	for(int i=0; i<lines; ++i){
		int star_w = (i < lines/2) ?  (i + 1) : (lines - i);
		int margins = hwidth - 2 * star_w;

		for(int j=0; j<star_w; ++j){
			cout<<"*";
		}
		for(int j=0; j<margins; ++j){
			cout<<" ";	
		}
		for(int j=0; j<star_w; ++j){
			cout<<"*";
		}
		cout<<"\n";
	}
}


void pattern_hollow_square(int lines){
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines; ++j){
			if(i == 0 || j == 0 || i == lines - 1 || j == lines -1){
				cout<<"*";
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}

void pattern_square_spiral_numbers(int lines){
	if(lines % 2 == 0){
		return;
	}
	int max_num = lines/2+1;
	int center_i = max_num-1;
	for(int i=0; i<lines; ++i){
		for(int j=0; j<lines; ++j){
			cout<< 1 + max(abs(center_i-i),abs(center_i-j));
		}
		cout<<"\n";
	}
}

int main(){
	pattern_square(25);
	cout<<"\n\n";
	pattern_triangle(25);
	cout<<"\n\n";
	pattern_triangle_nums(25);
	cout<<"\n\n";
	pattern_triangle_nums2(25);
	cout<<"\n\n";
	pattern_triangle_reverse(25);
	cout<<"\n\n";
	pattern_triangle_center(25);
	cout<<"\n\n";
	pattern_triangle_center_reverse(25);
	cout<<"\n\n";
	pattern_quadrilateral_center(24);
	cout<<"\n\n";
	pattern_quadrilateral_center(25);
	cout<<"\n\n";
	pattern_triangle_from_side(24);
	cout<<"\n\n";
	pattern_triangle_from_side(25);
	cout<<"\n\n";
	pattern_triangle_01(25);
	cout<<"\n\n";
	pattern_v_like_with_numbers(25);
	cout<<"\n\n";
	natural_numbers_in_triangle(25);
	cout<<"\n\n";
	pattern_triangle_abcd(25);
	cout<<"\n\n";
	pattern_triangle_abcd_reverse(25);
	cout<<"\n\n";
	pattern_triangle_abcd_colwise(25);
	cout<<"\n\n";
	pattern_triangle_abcd_fromlast(25);
	cout<<"\n\n";
	pattern_triangle_center_abcd(25);
	cout<<"\n\n";
	pattern_quadrilateral_invert_1(25);
	cout<<"\n\n";
	pattern_quadrilateral_invert_1(24);
	cout<<"\n\n";
	pattern_quadrilateral_invert_2(25);
	cout<<"\n\n";
	pattern_quadrilateral_invert_2(24);
	cout<<"\n\n";
	/* pattern_hollow_square(9); */
	/* cout<<"\n\n"; */
	/* pattern_square_spiral_numbers(9); */


}


