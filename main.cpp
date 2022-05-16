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

#include <iostream>
using namespace std;

void init()
{
    boost::shared_ptr< logging::core > core = logging::core::get();

    //Ohne diesen Aufruf bleibt die Uhrzeit leer
    logging::add_common_attributes();

    //Ausgabeort (simple Variante)
    //logging::add_file_log("sample.log");

    //Ausgabeort komplexe Variante
    logging::add_file_log
            (
                    keywords::file_name = "log.log",
                    keywords::target_file_name = "log%5N.log",
                    //keywords::file_name = "log%N.log",                                                                                                                                                                            /*< file name pattern >*/
                    keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
                    //keywords::max_size = 10 * 1024 * 1024,
                    //keywords::min_free_space = 100 * 1024 * 1024,
                    keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
                    keywords::auto_flush = true,
                    keywords::scan_method = boost::log::sinks::file::scan_matching,
                    keywords::max_files = 10,
                    keywords::open_mode = std::ios_base::out | std::ios_base::app,
                    keywords::enable_final_rotation = false,
                    keywords::format =                                                                                                                                              /*< log record format >*/
                            (
                                    expr::stream
                                            //<< expr::attr<unsigned int>("LineID")
                                            << "[" << expr::attr<boost::log::process_id>("ProcessID")
                                            << "][" << expr::attr<boost::log::thread_id>("ThreadID")
                                            << "][" << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%d-%m-%Y %H:%M:%S.%f") << "]"
                                            << "[" << logging::trivial::severity << "]"
                                            << expr::smessage
                            ));

    core->set_filter
            (
                    //Filter ist jetzt so festgelegt das minimal Info angezeigt wird
                    logging::trivial::severity >= logging::trivial::info
            );

    //Ist schon in add_common_attributes() enthalten
    //core->add_global_attribute("LineID", attrs::counter< unsigned int >(1));
}

int main(int, char*[])
{
    cout << "Ausgabe erfolgt in einem Logging-File im selben Ordner" << endl;

    init();

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    return 0;
}