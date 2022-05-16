//
// Created by kg on 13.05.22.
//

//g++ -O3 -o log.exe log.cpp -lboost_log -lboost_thread -lboost_filesystem -lboost_log_setup
//libboost_log.a und libboost_thread.a fuer trivial Textausgabe

#define BOOST_LOG_DYN_LINK
#define BOOST_ALL_DYN_LINK
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>        //Fuer das Logging selber
#include <boost/log/expressions.hpp>    //Fuer die Filter
//Fuer Ablage in Datei

#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/from_stream.hpp>

//Fuer Zeitangabe
#include <boost/log/support/date_time.hpp>

#include <fstream>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

using namespace std;

class timestamp_formatter_factory :
        public boost::log::basic_formatter_factory<char, boost::posix_time::ptime>
{
    public:
        formatter_type create_formatter(boost::log::attribute_name const& name, args_map const& args)
        {
            args_map::const_iterator it = args.find("format");
            if (it != args.end())
                return boost::log::expressions::stream << boost::log::expressions::format_date_time<boost::posix_time::ptime>(boost::log::expressions::attr<boost::posix_time::ptime>(name), it->second);
            else
                return boost::log::expressions::stream << boost::log::expressions::attr<boost::posix_time::ptime>(name);
        }
};

int main(int, char*[])
{
    cout << "Ausgabe erfolgt in einem Logging-File im selben Ordner" << endl;

    //Logging initialisation
    boost::log::register_formatter_factory("TimeStamp", boost::make_shared<timestamp_formatter_factory>());
    boost::log::add_common_attributes();

    //Read logging settings from file
    std::ifstream file("settings.ini");
    boost::log::init_from_stream(file);

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message 1";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message 2";
    BOOST_LOG_TRIVIAL(info) << "(" << __FILE__ << ", " << __LINE__ << ")" << ": " << "Test message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    return 0;
}