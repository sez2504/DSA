
#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int price[], int n, int S[])
{
	// A stackis created and index of first element is pushed
	stack<int> st;
	st.push(0);
	// stock Span of the first day is always equal to 1
	S[0] = 1;
	// Calculate span values for the rest of the days
	for (int i = 1; i < n; i++) {
		// while the stack is not empty and top of the stack is    smaller than current price, Pop elements from the stack
		while (!st.empty() && price[st.top()] < price[i])
			st.pop();
		// If stack becomes empty, then price[i] is
		// greater than all elements on left of it,
		// i.e., price[0], price[1], ..price[i-1]. Else
		// price[i] is greater than elements after
		// top of stack
		S[i] = (st.empty()) ? (i + 1) : (i - st.top());
		// Push the index of this element element to stack
		st.push(i);
	}
}

/*void calculateSpan(int prices[], int n, int spans[]) {
    if (n==0){
        return;
    }
    else if (n==1){
        spans[0]=1;
        return;
    }
    stack<int> deciding_index_numbers;
    spans[0]=1;
    deciding_index_numbers.push(0);
    bool span_empty=true;
    for (int i=1 ; i<n ; i++){
        if (deciding_index_numbers.empty()){
            //cout<<"I GREAT "<<i<<endl;
            deciding_index_numbers.push(i);
            span_empty=true;
            continue;
        }
        if (prices[i]<prices[deciding_index_numbers.top()] && span_empty){
            //cout<<"span empty : "<<span_empty<<"i : "<<i<<"spans i "<<spans[i]<<endl;
            deciding_index_numbers.push(i);
            spans[i]=1;
        }
        else if (prices[i]<prices[deciding_index_numbers.top()]){
            deciding_index_numbers.push(i);
        }
        else if (prices[i]==prices[deciding_index_numbers.top()]){
            spans[i]=1;
        }
        else{
            if (span_empty){
                spans[i]=spans[deciding_index_numbers.top()]+1;
            }
            else{
                spans[i]+=spans[deciding_index_numbers.top()];
            }
            //cout<<"spans i "<<spans[i]<<endl;
            span_empty=false;
            deciding_index_numbers.pop();
            i--;
            continue;
        }
        span_empty=true;
    }
}*/

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}