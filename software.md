---
layout: page
title: Software
permalink: /software/
---

<header class="page-header">
  <h2 class="page-title">Software</h2>
  <br>
</header>


<div style="display: grid; grid-template-columns: repeat(2, 1fr); gap: 20px; margin-bottom: 20px;">

  <!-- RevBayes -->
  <div style="display: flex; align-items: flex-start;">
    <img class="floatleft-small" src="/assets/images/RevBayes_logo.png" style="margin-right: 10px;">
    <div id="rcornersimage" style="background-color: #CECECE; padding: 10px; border-radius: 5px;">
      <p class="text" style="margin: 0;">
        <a href="https://revbayes.github.io/" target="_blank"><strong>RevBayes</strong></a> -
        <span style="background-color: #CECECE">Bayesian phylogenetic inference using probabilistic graphical models and an interpreted language.</span>
        RevBayes provides a flexible framework for performing Bayesian statistical analysis of phylogeny and related topics, such as divergence time estimation, diversification rate estimation, continuous and discrete trait evolution, and historical biogeography.
      </p>
    </div>
  </div>

  <!-- TESS -->
  <div style="display: flex; align-items: flex-start;">
    <img class="floatright-small" src="/assets/images/TESS_logo.png" style="margin-left: 10px;">
    <div id="rcornersimage" style="background-color: #CECECE; padding: 10px; border-radius: 5px;">
      <p class="text" style="margin: 0;">
        <a href="https://cran.r-project.org/web/packages/TESS/" target="_blank"><strong>TESS</strong></a> -
        An R package for <span style="background-color: #CECECE">Diversification Rate Estimation and Fast Simulation of Reconstructed Phylogenetic Trees</span> under Tree-Wide Time-Heterogeneous Birth-Death Processes Including Mass-Extinction Events.
        TESS both provides the likelihood function as well as reversible-jump method to estimate global diversification rates and rate shifts.
      </p>
    </div>
  </div>

  <!-- PESTO -->
  <div style="display: flex; align-items: flex-start;">
    <img class="floatleft-small" src="/assets/images/PESTO_logo.png" style="margin-right: 10px;">
    <div id="rcornersimage" style="background-color: #CECECE; padding: 10px; border-radius: 5px;">
      <p class="text" style="margin: 0;">
        <a href="https://github.com/kopperud/Pesto.jl" target="_blank"><strong>Pesto.jl</strong></a> - A <a href="https://julialang.org/" target="_blank">Julia</a> module for <span style="background-color: #CECECE">Phylogenetic Estimation of Shifts in the Tempo of Origination</span>.
        Under the birth-death-shift process (Höhna et al. 2019, biorxiv), the diversification rate is allowed to shift across the phylogeny, where branch-specific diversification rates, as well as the number of rate shifts can be inferred.
        Pesto is implemented using an efficient estimation algorithm, allowing for fast inferences even for large phylogenies with thousands of species.
      </p>
    </div>
  </div>

  <!-- Convenience -->
  <div style="display: flex; align-items: flex-start;">
    <img class="floatright-small" src="/assets/images/convenience_1.jpg" style="margin-left: 10px;">
    <div id="rcornersimage" style="background-color: #CECECE; padding: 10px; border-radius: 5px;">
      <p class="text" style="margin: 0;">
        <a href="https://github.com/lfabreti/convenience" target="_blank"><strong>Convenience</strong></a> -
        A R package for <span style="background-color: #CECECE">convergence diagnostics in Bayesian Phylogenetic MCMC</span>.
        This R package helps in convergence assessment for phylogenetic inference not only in continuous parameters but also in the trees sampled as well.
      </p>
    </div>
  </div>

</div>
