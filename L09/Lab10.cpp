#include <iostream>
#include <string>
using namespace std;

class Util {
public:
    static string* copyStrings(string* values, int count) {
        if (count <= 0 || values == nullptr)
            return nullptr;

        string* copy = new string[count];
        for (int i = 0; i < count; i++) copy[i] = values[i];
        return copy;
    }

    static int* copyInts(int* values, int count) {
        if (count <= 0 || values == nullptr)
            return nullptr;

        int* copy = new int[count];
        for (int i = 0; i < count; i++) copy[i] = values[i];
        return copy;
    }
};
class Series {
private:
    string name = "";
    int noEpisodes = 0;
    string* episodes = nullptr;

    int* ratings = nullptr;
    int noRatings = 0;

public:
    enum Genre { DRAMA, ACTION, COMEDY, ROMCOM, SITCOM };
    Genre genre = DRAMA;
    string platform = "";
    Series() {}

    Series(string platform, string name, Genre genre, string* eps, int noEps, int* r, int noR) {
        this->platform = platform;
        this->setName(name);
        this->setGenre(genre);
        this->setEpisodes(eps, noEps);
        this->setRatings(r, noR);
    }
    Series(string platform) {
        this->platform = platform;
    }

    Series(const Series& s) {
        cout << "Copy ctor\n";
        platform = s.platform;
        name = s.name;
        noEpisodes = s.noEpisodes;
        episodes = Util::copyStrings(s.episodes, s.noEpisodes);
        noRatings = s.noRatings;
        ratings = Util::copyInts(s.ratings, s.noRatings);
        genre = s.genre;
    }

    ~Series() {
        delete[] episodes;
        delete[] ratings;
    }

    string getName() const {
        return name;
    }
    int getNoEpisodes() const {
        return noEpisodes;
    }
    string* getEpisodes() const {
        return Util::copyStrings(episodes, noEpisodes);
    }
    int* getRatings() const {
        return Util::copyInts(ratings, noRatings);
    }
    int getRatingsCount() const {
        return noRatings;
    }
    Genre getGenre() const {
        return genre;
    }

    static string genreToString(Genre g) {
        switch (g) {
        case DRAMA:
            return "Drama";
        case ACTION:
            return "Action";
        case COMEDY:
            return "Comedy";
        case ROMCOM:
            return "RomCom";
        case SITCOM:
            return "Sitcom";
        default:
            return "Unknown";
        }
    }

    void setName(string n) { name = n.empty() ? "Unknown Series" : n; }
    void setGenre(Genre g) { genre = g; }

    void setEpisodes(string* eps, int count) {
        delete[] episodes;
        episodes = (count > 0 && eps != nullptr) ? Util::copyStrings(eps, count) : nullptr;
        noEpisodes = (count > 0 && eps != nullptr) ? count : 0;
    }

    void setRatings(int* r, int count) {
        for (int i = 0; i < count; i++) if (r[i] < 0)
            return; // invalid data
        delete[] ratings;
        ratings = (count > 0 && r != nullptr) ? Util::copyInts(r, count) : nullptr;
        noRatings = (count > 0 && r != nullptr) ? count : 0;
    }
    void addEpisode(string title) {
        if (title.empty())
            return;
        string* newList = new string[noEpisodes + 1];
        for (int i = 0; i < noEpisodes; i++) newList[i] = episodes[i];
        newList[noEpisodes] = title;
        delete[] episodes;
        episodes = newList;
        noEpisodes++;
    }

    string getEpisodeTitle(int index) const {
        if (index < 0 || index >= noEpisodes)
            return "invalid episode index  :( ";
        return episodes[index];
    }

    void print() const {
        cout << "\nPlatform: " << platform;
        cout << "\nSeries: " << name;
        cout << "\nGenre: " << genreToString(genre);
        cout << "\nEpisodes (" << noEpisodes << "):";
        for (int i = 0; i < noEpisodes; i++) cout << "\n  - " << episodes[i];
        cout << "\nRatings: ";
        for (int i = 0; i < noRatings; i++) cout << ratings[i] << " ";
        cout << "\n";
    }

    // Class type - +,-, ++,--, +=, *=
    // Boolean operators ==, !=, !, >, <= 
    // void (not recommended)
    // misc. <<,>> ostream, istream

    //(^, &, |)

    void operator=(const Series* source) {
        if (this == source) return;

        cout << "Op. =  is called";
        this->name = source->name;
        this->genre = source->genre;
        this->noEpisodes = source->noEpisodes;
        this->noRatings = source->noRatings;

        if (this != source) {
            if (this->episodes != nullptr) {
                delete[] this->episodes;
            }

            if (this->ratings != nullptr) {
                delete[] this->ratings;
            }
        }

        this->episodes = new string[this->noEpisodes];
        this->ratings = new int[this->noRatings];

        for (int i = 0; i < this->noEpisodes; i++) {
            this->episodes[i] = source->episodes[i];
        }

        for (int i = 0; i < this->noRatings; i++) {
            this->ratings[i] = source->ratings[i];
        }

    }

    Series& operator=(const Series& source) {
        if (this == &source) return *this; // do this OR

        cout << "Op. =  is called";
        this->name = source.name;
        this->genre = source.genre;
        this->noEpisodes = source.noEpisodes;
        this->noRatings = source.noRatings;

        if (this != &source) { // OR do this
            if (this->episodes != nullptr) {
                delete[] this->episodes;
            }

            if (this->ratings != nullptr) {
                delete[] this->ratings;
            }
        }

        this->episodes = new string[this->noEpisodes];
        this->ratings = new int[this->noRatings];

        for (int i = 0; i < this->noEpisodes; i++) {
            this->episodes[i] = source.episodes[i];
        }

        for (int i = 0; i < this->noRatings; i++) {
            this->ratings[i] = source.ratings[i];
        }

        return *this;

    }

    Series* operator+(const string name) {
        Series* newSeries = new Series(*this);
        newSeries->name += name;

        return newSeries;
    }

    Series& operator++() { // prefixed
        this->addEpisode("default episode");
        return *this;
    }

    Series operator++(int) { //postfixed
        Series copy = *this;
        this->addEpisode("default episode");
        return copy;
    }

    friend void operator<<(ostream& out, Series s);

};

void operator<<(ostream& out, Series s) { // obj << cout
    out << "\nPlatform: " << s.platform;
    out << "\nSeries: " << s.name;
    out << "\nGenre: " << s.genreToString(s.genre);
    out << "\nEpisodes (" << s.noEpisodes << "):";
    for (int i = 0; i < s.noEpisodes; i++) out << "\n  - " << s.episodes[i];
    out << "\nRatings: ";
    for (int i = 0; i < s.noRatings; i++) out << s.ratings[i] << " ";
    out << "\n";
}


Series combineSeasons(const Series& s1, const Series& s2) {
    Series result;
    if (s1.getName() != s2.getName()) {
        cout << "\nyou can't combine them,since names differ :) .\n";
        return result;
    }
    result.platform = s1.platform;
    result.setName(s1.getName());

    int n1 = s1.getNoEpisodes(), n2 = s2.getNoEpisodes(), total = n1 + n2;
    string* eps1 = s1.getEpisodes();
    string* eps2 = s2.getEpisodes();
    string* combined = new string[total];
    for (int i = 0; i < n1; i++)
        combined[i] = eps1[i];
    for (int i = 0; i < n2; i++)
        combined[n1 + i] = eps2[i];
    result.setEpisodes(combined, total);
    delete[] eps1;
    delete[] eps2;
    delete[] combined;

    int* rt = s1.getRatings();
    result.setRatings(rt, s1.getRatingsCount());
    delete[] rt;

    result.setGenre(s1.getGenre());
    return result;
}

Series combineSeasons(const Series& s1, const Series& s2, const Series& s3) {
    Series result;
    if (s1.getName() != s2.getName()) {
        cout << "\nyou can't combine them,since names differ :) .\n";
        return result;
    }
    result.platform = s1.platform;
    result.setName(s1.getName());

    int n1 = s1.getNoEpisodes(), n2 = s2.getNoEpisodes(), total = n1 + n2;
    string* eps1 = s1.getEpisodes();
    string* eps2 = s2.getEpisodes();
    string* combined = new string[total];
    for (int i = 0; i < n1; i++)
        combined[i] = eps1[i];
    for (int i = 0; i < n2; i++)
        combined[n1 + i] = eps2[i];
    result.setEpisodes(combined, total);
    delete[] eps1;
    delete[] eps2;
    delete[] combined;

    int* rt = s1.getRatings();
    result.setRatings(rt, s1.getRatingsCount());
    delete[] rt;

    result.setGenre(s1.getGenre());
    return result;
}

//Series doNothing() {
//    Series s("Netflix");
//    return s;
//}

int main() {
    Series s1;
    s1.platform = "Netflix";
    s1.setName("Modern Family");
    s1.setGenre(Series::SITCOM);
    string eps1[3] = { "S1 E1", "S1 E2", "S1 E3" };
    s1.setEpisodes(eps1, 3);
    int r1[3] = { 6, 7, 9 };
    s1.setRatings(r1, 3);
    //Series copy(s1);
    /*
    Series s2;
    s2.platform = "Disney+";
    s2.setName("Modern Family");
    s2.setGenre(Series::SITCOM);
    string eps2[2] = { "S2 E1", "S2 E2" };
    s2.setEpisodes(eps2, 2);
    int r2[2] = { 8, 7 };
    s2.setRatings(r2, 2);

    Series combined = combineSeasons(s1, s2);
    combined.print();

    */
    /* Series s = doNothing();
     s.print();*/

    Series c = s1; // copy ctor
    c = &c; // equals op.
    c.print();

    ++s1;

    s1.print();

    //operator=(c, operator=(s1, c));

    cout << "*************************\n\n";

    s1 = *(s1 + "New");
    s1.print();
    s1++;
    s1.print();

    int x = 4;
    x + 4;
    cout << endl << x;

    cout << s1;

    return 0;
}
