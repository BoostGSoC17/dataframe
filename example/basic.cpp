

// instantiation, assignment and printing.

int main() {

	using namespace boost::numeric::ublas;
	
	vector <int> a(2), b(2);
	a(0) = 1, a(1) = 2;
	b(0) = 2, b(1) = 10;
	df_column data(2);
	data(0) = a;
	data(1) = b;
	vector < std::string> h(2);
	h(0) = "a", h(1) = "b";
	data_frame df(h, data);

	// prints the data column-wise
	df.print();
	
	// assign entire columns of a data_frame
	df[0] = df[1];
	df.print();

	// assigns the value of data_frame df to data_frame df2;
	data_frame df2;
	df2 = df;
	df2.print();

	return 0;
}