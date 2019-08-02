---
layout: page
title: Research
permalink: /research/
---

<!--
Phylogenies depict the evolutionary relationships among species. Much of the current interest in phylogenetics comes from advances in DNA sequencing technologies that now allow the phylogenetic comparison of hundreds or thousands of genes. The availability of genome-size dataset enable new research directions, such as, studying heterogeneity in the process of molecular evolution due to adaptation and studying differential evolutionary histories of genes. A major challenge in phylogenetics is to infer events that occurred million of years ago while only having data from extant species. Nevertheless, new mathematical and statistical methods continue to advance and improve our ability to effectively study these problems.
-->
<p class="text">
Our research is focused on several aspects of theoretical and computational phylogenetics. Here we list the main directions, but see the publications for more details.
</p>

<br />

<!-- Section 1 -->
<div class="container-small">
<img class="floatleft" src="/assets/images/Figure_1_v2.png">
<div id="rcornersbox1">
    <h2>Robust Estimation of Gene Trees</h2>
<!--
Gene trees provide the fundamental information in molecular phylogenetics. Originally, a single or a few well curated genes were used for phylogenetic inference. Then, the species tree was assumed to be the same as the estimated gene tree. Today, we often have hundreds or thousands of loci in our datasets. Hence, we can examine comparatively the substitution process for each single locus and ask new research questions, such as: (a) Did this gene evolve under selective pressures? (b) Did this gene evolve under a time-reversible or non-reversible model? (c) Did the substitution process change along the lineages of the tree? (d) Did this gene evolve under a strict molecular clock?
To answer these questions we develop more realistic substitution models in RevBayes. For example, we have designed RevBayes to model heterogeneous substitution process along the branches of a tree which can be used to model variation in GC content among lineages as well as variation in selective pressures along lineages. Additionally, we develop more efficient methods to test for the relative fit a model (Höhna et al. 2017, Bioinformatics) and develop new methods, e.g., posterior predictive testing, to test the absolute fit a model (Höhna et al. 2017, MBE). Moreover, this work is fundamental for any phylogenetic analysis because robust and accurate estimates of gene trees are crucial for all research areas using phylogenetics.
-->
    <p class="text">
        Gene trees provide fundamental information about the processes in genetic evolution which is contained in the variation of their topology and branching times.
        In this work we are focused on how to reliably estimate gene trees by developing more robust statistical methods.
    </p>

</div>
</div>

<br>
<br>

<!-- Section 2 -->
<div class="container-small">
<img class="floatright" src="/assets/images/Figure_2_v2.png">
<div id="rcornersbox2">
    <h2>Understanding Discordance Between Species Trees and Gene Trees</h2>
<!--
Phylogenetic inferences from genomic data consist of many loci. Each locus is assumed to evolve independently because recombination breaks linkage between loci. Independent loci can therefore have distinct evolutionary histories and cause gene tree species tree incongruence. For example, the following scenarios can cause incongruent gene trees: (a) simple population genetic processes (i.e., the coalescent), (b) migration and thus gene-flow between species/populations , and (c) gene-duplication and gene-loss. Even though, gene-tree discordance is a major challenge in species-tree estimation, its identification also provides key information about biological processes. Our first key question is the estimation of species trees when the underlying gene trees are discordant. Specifically, we are working on more realistic models that incorporate different causes of gene-tree incongruence such as the multispecies coalescent with migration model. This work also entails new algorithm development and theory design for more efficient computation of species trees from thousands of gene trees. Our second key question is the estimation of divergence times under complex gene-tree histories (e.g., Martin and Höhna 2017, Martin et al. 2017). Gene trees are older than species/population divergence under a multispecies coalescent model, but gene trees are younger than species/population divergence in the presence of migration. This problem is exacerbated for young species. Thus, we aim to obtain improved and robust estimated of divergences times using our new developments on a multispecies coalescent with migration model. Finally, this multispecies coalescent with migration model could be used for improved species delimitation in the presence of migration.
-->
    <p class="text">
        The following biological scenarios can cause incongruent gene trees: (a) simple population genetic processes (i.e., the coalescent), (b) migration and thus gene-flow between species/populations , and (c) gene-duplication and gene-loss.
        We are working on more realistic models that incorporate different causes of gene-tree incongruence such as the multispecies coalescent with migration model.
        This work also entails new algorithm development and theory design for more efficient computation of species trees from thousands of gene trees.
    </p>

</div>
</div>

<br>
<br>

<!-- Section 3 -->
<div class="container-small">
<img class="floatleft" src="/assets/images/Figure_4.png">
<div id="rcornersbox1">
    <h2>Inference of Macroevolutionary Processes</h2>

    <p class="text">
        Our ultimate goal is to infer diversification rates through time and among lineages and identify correlations to genetic, phenotypic and/or environmental factors that impact diversification rate.
        For example, we developed a statistical method to identify correlations between rates of diversification and environmental variables, such as changes in atmospheric CO2.

        In our future work, we want to incorporate fossil occurrence information in our models of lineage diversification.
    </p>

</div>
</div>
