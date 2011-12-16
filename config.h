#ifndef CONFIG_H
#define CONFIG_H

#include <assert.h>
#include <QString>

class Config
{
public:
    Config();
    ~Config()
    {
        my = NULL;
    }

    /// Set the defoult value into the current configuration
    /// of the program
    void LoadDefoultValues();

    /// Load the configuration of the program from a file
    /// \param name The configuration will read from this file
    /// \return String with the errore message in case of error,
    ///         an empty string in case of success
    QString LoadFromFile(const QString &name);

    /// Save the current configuration of the program into a file
    /// \param name The configuration will write in this file
    /// \return String with the errore message in case of error,
    ///         an empty string in case of success
    QString SaveToFile(const QString &name);

    bool getShowAbout()
    {
        return show_about;
    }

    void setShowAbout(bool value)
    {
        show_about=value;
    }

    int getDistanceLeftSide()
    {
        return distance_left_side;
    }

    void setDistanceLeftSide(int value)
    {
        distance_left_side=value;
    }

    int getDistanceRightSide()
    {
        return distance_right_side;
    }

    void setDistanceRightSide(int value)
    {
        distance_right_side=value;
    }

    int getHeight()
    {
        return height;
    }

    void setHeight(int value)
    {
        height=value;
    }

    int getLineFetchingFrequency()
    {
        return line_fetching_fr;
    }

    void setLineFetchingFrequency(int value)
    {
        line_fetching_fr=value;
    }

    int getCaptureTime()
    {
        return capture_time;
    }

    void setCaptureTime(int value)
    {
        capture_time=value;
    }

    bool getSaveOutput()
    {
        return save_output;
    }

    void setSaveOutput(bool value)
    {
        save_output=value;
    }

    QString getFilePath()
    {
        return file_path;
    }

    void setFilePath(QString value)
    {
        file_path=value;
    }

    QString getFileName()
    {
        return file_name;
    }

    void setFileName(QString value)
    {
        file_name=value;
    }

    static Config *getMonoton()
    {
        assert(my!=NULL);
        return my;
    }

protected:
    /// If is true the about window will show at start up
    bool show_about;
    /// Last value used as distance from right side of
    /// the captured image
    int distance_left_side;
    /// Last value used as distance from left side of
    /// the captured image
    int distance_right_side;
    /// Last value used as height of the captured image
    int height;
    /// Last value used as line fetching frequence
    int line_fetching_fr;
    /// Last value used as capture time
    int capture_time;
    /// Last value used as save output on disc
    bool save_output;
    /// Last position used for save the captured image
    /// on disc
    QString file_path;
    /// Last file name used for save the captured image
    /// on disc
    QString file_name;

private:
    static Config *my;
};

#endif // CONFIG_H
