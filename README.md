# OTUPot
# Language: C++
# Input: TXT
# Output: prefix
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 1.9.1, Python 2.7

Plot a plot of OTU abundances in a set of samples.

The plugin accepts a TXT file of keyword-value pairs, tab-delimited:

otutable (BIOM file of OTUs)
mapping (TXT file of mappings)

It produces output plots, into the provided output folder.  Additionally it will generate BIOM files at each level of the taxonomic tree.
