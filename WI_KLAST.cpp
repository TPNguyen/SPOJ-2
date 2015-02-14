#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class File
{
public:
    File(string n, int s) : name(n), size(s) {}
    string name;
    int size;
    static bool filename(string fn);
};

class WIZUT_2009
{
public:
    WIZUT_2009(int c, int cs) : clustersMax(c), clusterSize(cs), clusters(0) {}
    void create(string name);
    void del(string name);
    void write(string name, int bytes);
    void truncate(string name, int bytes);
    int freeClusters();
private:
    int clustersMax;//liczba klastrow dostepnych na dysku
    int clusterSize;//rozmiar klastra na dysku w bajtach
    int clusters;//liczba zajetych klastrow
    vector<File> files;
    vector<File>::iterator findFile(string name);
    int bytesToClusters(int b);
};

bool filename(string fn);

int main()
{
    unsigned n; 
    unsigned r; 
    int bytes;
    string line;
    string command;
    string filename;
    stringstream ss;

    cin >> n >> r;

    WIZUT_2009 fs(n, r);

    while (getline(cin, line))
    {
        ss.clear();
        ss.str(line);
        ss >> command >> filename >> bytes;
        if (command == "WRITE")
            fs.write(filename, bytes);
        else if (command == "TRUNCATE")
            fs.truncate(filename, bytes);
        else if (command == "CREATE")
            fs.create(filename);
        else if (command == "DELETE")
            fs.del(filename);
    }

    cout << fs.freeClusters() << endl;

    return 0;
}

bool File::filename(string fn)
{
    if (fn.length() <= 11 && fn != "")
    {
        for (unsigned i = 0; i < fn.length(); ++i)
            if (!isdigit(fn[i]) && !isupper(fn[i]))
                return false;
        return true;
    }
    else
        return false;
}

void WIZUT_2009::create(string name)
{
    if (File::filename(name) && findFile(name) == files.end())
        files.push_back(File(name, 0));
}

void WIZUT_2009::del(string name)
{
    vector<File>::iterator it = findFile(name);

    if (it != files.end())
    {
        clusters -= bytesToClusters(it->size);
        files.erase(it);
    }
}

void WIZUT_2009::write(string name, int bytes)
{
    vector<File>::iterator it = findFile(name);

    if (it == files.end())
        return;

    if (bytes < 1 || bytes > 10000)
        return;

    int newClusters = clusters - bytesToClusters(it->size) 
            + bytesToClusters(it->size + bytes);

    if (newClusters <= clustersMax)
    {
        it->size += bytes;
        clusters = newClusters;
    }
}

void WIZUT_2009::truncate(string name, int bytes)
{
    vector<File>::iterator it = findFile(name);

    if (it == files.end())
        return;

    if (bytes < 1 || bytes > 10000)
        return;

    if (bytes <= it->size)
    {
        clusters = clusters - bytesToClusters(it->size) 
            + bytesToClusters(it->size - bytes);
        it->size -= bytes;
    }
}

vector<File>::iterator WIZUT_2009::findFile(string name)
{
    vector<File>::iterator it;
    
    for (it = files.begin(); it != files.end(); ++it)
        if (it->name == name)
            break;

    return it;
}

int WIZUT_2009::bytesToClusters(int b)
{
    return b / clusterSize + (b % clusterSize ? 1 : 0);
}

int WIZUT_2009::freeClusters()
{
    return clustersMax - clusters;
}
