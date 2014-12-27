#include <iostream>
#include <string>
#include <vector>

#include <fast-cpp-csv-parser/csv.h>

#include "dummy_data_line.hpp"


std::vector<dummy_data_line>
parse_data_lines(std::string csv_file_name)
{
	std::vector<dummy_data_line> data_lines;

	io::CSVReader<
		4,
		io::trim_chars<>,
		io::double_quote_escape<' ', '"'>> csv_reader(csv_file_name);

	dummy_data_line data_line = {};

	while(csv_reader.read_row(data_line.name, data_line.last_name,
		data_line.age, data_line.address)) {

		data_lines.push_back(data_line);
	}

	return data_lines;
}


int
main(int argc, char *args[])
{
	if (argc < 2) {
		std::cerr <<"Error: bad csv file.\n";
		return -1;
	}

	std::vector<dummy_data_line> data_lines = parse_data_lines(args[1]);

	for (std::vector<dummy_data_line>::iterator data_lines_it =
		data_lines.begin(); data_lines_it != data_lines.end();
		++data_lines_it) {

		std::cout <<data_lines_it->name <<", "
			<<data_lines_it->last_name <<", "
			<<data_lines_it->age <<", "
			<<data_lines_it->address <<".\n";
	}
}
