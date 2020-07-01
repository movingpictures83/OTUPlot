#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "OTUPlotPlugin.h"

void OTUPlotPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void OTUPlotPlugin::run() {
   
}

void OTUPlotPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; rm -rf "+file+"; summarize_taxa_through_plots.py ";
 command += "-i "+parameters["biomfile"]+" -m "+parameters["mapping"]+" -o "+file+"; cp "+file+"/* "+file+"/..";
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<OTUPlotPlugin> OTUPlotPluginProxy = PluginProxy<OTUPlotPlugin>("OTUPlot", PluginManager::getInstance());
