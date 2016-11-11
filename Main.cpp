// Name: Pearson, Matthew
// Project: 2A
 
#include "Library.h"

void main() {
	Library library;
	omp_set_num_threads(4);

#pragma omp parallel sections
	{
#pragma omp section
		{
			library.add_book("Software Engineering");
			library.add_book("Chemistry");
		}
#pragma omp section
		{
			library.add_customer("Adam");
			library.add_customer("Sam");
			library.add_customer("Oprah");
			library.add_customer("Jeff");
		}
	}

	library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
	library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US));

	library.pass_next("Chemistry", Date(2015, 3, 5, DateFormat::US));
	library.pass_next("Chemistry", Date(2015, 3, 7, DateFormat::US));
	library.pass_next("Chemistry", Date(2015, 3, 15, DateFormat::US));
	library.pass_next("Chemistry", Date(2015, 3, 20, DateFormat::US));

	library.pass_next("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.pass_next("Software Engineering", Date(2015, 4, 6, DateFormat::US));
	library.pass_next("Software Engineering", Date(2015, 4, 11, DateFormat::US));
	library.pass_next("Software Engineering", Date(2015, 4, 20, DateFormat::US));
}