---
layout: page
title: Research
permalink: /research/
---

Phylogenies depict the evolutionary relationships among species. Much of the current interest in phylogenetics comes from advances in DNA sequencing technologies that now allow the phylogenetic comparison of hundreds or thousands of genes. The availability of genome-size dataset enable new research directions, such as, studying heterogeneity in the process of molecular evolution due to adaptation and studying differential evolutionary histories of genes. A major challenge in phylogenetics is to infer events that occurred million of years ago while only having data from extant species. Nevertheless, new mathematical and statistical methods continue to advance and improve our ability to effectively study these problems.


<!-- Section 1 -->
<img class="floatleft" src="/assets/images/tree.jpg" width="350">
<div id="rcornersbox1">
    <p class="lead">
        <h2>Robust Estimation of Gene Trees</h2>
Gene trees provide the fundamental information in molecular phylogenetics. Originally, a single or a few well curated genes were used for phylogenetic inference. Then, the species tree was assumed to be the same as the estimated gene tree. Today, we often have hundreds or thousands of loci in our datasets. Hence, we can examine comparatively the substitution process for each single locus and ask new research questions, such as: (a) Did this gene evolve under selective pressures? (b) Did this gene evolve under a time-reversible or non-reversible model? (c) Did the substitution process change along the lineages of the tree? (d) Did this gene evolve under a strict molecular clock?

To answer these questions we develop more realistic substitution models in RevBayes. For example, we have designed RevBayes to model heterogeneous substitution process along the branches of a tree which can be used to model variation in GC content among lineages as well as variation in selective pressures along lineages. Additionally, we develop more efficient methods to test for the relative fit a model (Höhna et al. 2017, Bioinformatics) and develop new methods, e.g., posterior predictive testing, to test the absolute fit a model (Höhna et al. 2017, MBE). Moreover, this work is fundamental for any phylogenetic analysis because robust and accurate estimates of gene trees are crucial for all research areas using phylogenetics.
    </p>
</div>

<br>

<!-- Section 2 -->
<img class="floatright" src="/assets/images/tree.jpg" width="350">
<div id="rcornersbox2">
    <p class="lead">
        <h2>Understanding Discordance Between Species Trees and Gene Trees</h2>
Phylogenetic inferences from genomic data consist of many loci. Each locus is assumed to evolve independently because recombination breaks linkage between loci. Independent loci can therefore have distinct evolutionary histories and cause gene tree species tree incongruence. For example, the following scenarios can cause incongruent gene trees: (a) simple population genetic processes (i.e., the coalescent), (b) migration and thus gene-flow between species/populations , and (c) gene-duplication and gene-loss. Even though, gene-tree discordance is a major challenge in species-tree estimation, its identification also provides key information about biological processes. Our first key question is the estimation of species trees when the underlying gene trees are discordant. Specifically, we are working on more realistic models that incorporate different causes of gene-tree incongruence such as the multispecies coalescent with migration model. This work also entails new algorithm development and theory design for more efficient computation of species trees from thousands of gene trees. Our second key question is the estimation of divergence times under complex gene-tree histories (e.g., Martin and Höhna 2017, Martin et al. 2017). Gene trees are older than species/population divergence under a multispecies coalescent model, but gene trees are younger than species/population divergence in the presence of migration. This problem is exacerbated for young species. Thus, we aim to obtain improved and robust estimated of divergences times using our new developments on a multispecies coalescent with migration model. Finally, this multispecies coalescent with migration model could be used for improved species delimitation in the presence of migration.
    </p>
</div>


<!-- Section 3 -->
<img class="floatright" src="/assets/images/tree.jpg" width="350">
<div id="rcornersbox2">
    <p class="lead">
        <h2>Inference of Macroevolutionary Processes</h2>
Many evolutionary processes entail differential rates of diversification: e.g., adaptive radiation, diversity-dependent diversification, key innovations, and mass extinction. Current methods for exploring these evolutionary processes involves the use of stochastic birth-death branching process models, where rates of diversification may be (a) time-dependent, (b) lineage-specific, or (c) character-dependent. Our ultimate goal is to infer diversification rates through time and among lineages and identify correlations to genetic, phenotypic and/or environmental factors that impact diversification rate.

In our previous work we extended the theory on birth-death models (Höhna, 2013, Bioinformatics; Höhna, 2015, JTB; Höhna et al., 2016, Bioinformatics) and implemented computationally efficient methods to infer episodic changes in diversification rate, including cases in which species sampling is incomplete (Höhna, 2014, PLoS one; Höhna et al., 2011, MBE). In a recent study, we used this new approach to show that the diversity of conifers was impacted by one major mass-extinction event approximately 23 million years ago (May et al., 2016, MEE), an event that coincided with the known timing of the increase of more arid, grassland ecosystems. In an upcoming study, we also developed a statistical method to identify correlations between rates of diversification and environmental variables, such as changes in atmospheric CO2. We are currently testing this new method using the daisy flower family, Asteraceae. 

Our next steps are to develop and implement a robust model for inferring diversification-rate variation across lineages that correct problems with previous methods (see Moore et al., 2016, PNAS). These models allow us to study diversification rate-variation through-time and among lineages. Currently, we obtain lineage-specific diversification rate estimates independently of potentially correlated factors. Future projects in this research stream include the development of statistical methods to infer correlations between time-dependent and lineage-specific diversification rates with species traits (such as morphological traits), substitution rates and environmental factors/habitat.

Finally, we want to incorporate fossil occurrence information in our models of lineage diversification. Current models that use only present-day taxa have clearly lower statistical power at inferring historical events. Molecular phylogenies combined with fossil occurrence data will provide us a unique opportunity in studying the mode of lineage diversification over time and among clades.

    </p>
</div>


<!-- Section 4 -->
<img class="floatright" src="/assets/images/tree.jpg" width="350">
<div id="rcornersbox2">
    <p class="lead">
        <h2>Software for Phylogenetic Inference</h2>
Recently, we introduced the concept of probabilistic graphical models to phylogenetics (Höhna et al., 2014, Systematic Biology). This model representation has the advantage of being easily extendable to more complex (i.e., realistic) models. We combined and implemented this mathematical and statistical theory in a new computer program called RevBayes (Höhna et al., 2016, Systematic Biology). RevBayes is a general and flexible software mostly intended for Bayesian inference of phylogeny. Programs for Bayesian inference of phylogeny currently implement a unique and fixed suite of models. Consequently, users of these software packages are simultaneously forced to use a number of programs for a given study, while also lacking the freedom to explore models that have not been deemed interesting by the developers of those programs. RevBayes seeks to address these problems. The features of RevBayes include unrooted and rooted phylogeny inference, divergence time estimation, diversification rate estimation, historical biogeography, and discrete and continuous trait evolution. 

Development in RevBayes is ongoing and extremely active. Specifically, we use RevBayes as a framework to implement and test new statistical models as well as new algorithms and methods for more efficient inference and hypothesis testing. 
    </p>
</div>

