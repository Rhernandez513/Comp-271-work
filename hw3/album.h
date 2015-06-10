class Album {
	private:
		char * artist;	// band or singersi name
		char * title;	// title of the album
		int year_released;	// year the album is released
		char * record_label;	// name of company produced album
		int num_songs;	// number of songs on the album
		int num_minutes_long;	// length (mins) of album
		char * genre;	// genre of artist (eg, rock, pop, â¦)
	public:
		//constructors
		Album();
		Album(char *& a, char *& t);

		//deconstructor
		~Album();

		//accessors and mutators
		bool set_artist(char * a);
		bool set_title(char * t);
		bool set_year_released(int value);
		bool set_record_label(char *& label);
		bool set_num_songs(int value);
		bool set_num_minutes_long(int value);
		bool set_genre(char * g);
		bool get_artist(char *& a);
		bool get_title(char *& t);
		int get_year_released();
		bool get_record_label(char *& label);
		int get_num_songs();
		int get_num_minutes_long();
		bool get_genre(char *& g);
		
		//additional functions for homework 3
		bool write_console(); //think of this as a 'toString' like in C# write out every piece of info for obj
		//think of write_file grabbing all the info like write_console but putting it into a file if data exist
		bool write_file(char * file_name); //return true if a value to write false otherwise	
};
