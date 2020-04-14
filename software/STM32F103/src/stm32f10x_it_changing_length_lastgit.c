





<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
  <link rel="dns-prefetch" href="https://github.githubassets.com">
  <link rel="dns-prefetch" href="https://avatars0.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars1.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars2.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars3.githubusercontent.com">
  <link rel="dns-prefetch" href="https://github-cloud.s3.amazonaws.com">
  <link rel="dns-prefetch" href="https://user-images.githubusercontent.com/">



  <link crossorigin="anonymous" media="all" integrity="sha512-FG+rXqMOivrAjdEQE7tO4BwM1poGmg70hJFTlNSxjX87grtrZ6UnPR8NkzwUHlQEGviu9XuRYeO8zH9YwvZhdg==" rel="stylesheet" href="https://github.githubassets.com/assets/frameworks-146fab5ea30e8afac08dd11013bb4ee0.css" />
  
    <link crossorigin="anonymous" media="all" integrity="sha512-Eq0844C4NpzEkZmg4YBfbHHyqZUpy70R5sw7VvsR3UAK8DkkFHpE+TtwKkxVOuGDufjdo2Y/V30+j4jMvydnVQ==" rel="stylesheet" href="https://github.githubassets.com/assets/github-12ad3ce380b8369cc49199a0e1805f6c.css" />
    
    
    
    


  <meta name="viewport" content="width=device-width">
  
  <title>allcolours/stm32f10x_it.c at master · microresearch/allcolours</title>
    <meta name="description" content="all the colours of the noise. Contribute to microresearch/allcolours development by creating an account on GitHub.">
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
  <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
  <meta property="fb:app_id" content="1401488693436528">

    <meta name="twitter:image:src" content="https://avatars2.githubusercontent.com/u/902925?s=400&amp;v=4" /><meta name="twitter:site" content="@github" /><meta name="twitter:card" content="summary" /><meta name="twitter:title" content="microresearch/allcolours" /><meta name="twitter:description" content="all the colours of the noise. Contribute to microresearch/allcolours development by creating an account on GitHub." />
    <meta property="og:image" content="https://avatars2.githubusercontent.com/u/902925?s=400&amp;v=4" /><meta property="og:site_name" content="GitHub" /><meta property="og:type" content="object" /><meta property="og:title" content="microresearch/allcolours" /><meta property="og:url" content="https://github.com/microresearch/allcolours" /><meta property="og:description" content="all the colours of the noise. Contribute to microresearch/allcolours development by creating an account on GitHub." />

  <link rel="assets" href="https://github.githubassets.com/">
  <link rel="web-socket" href="wss://live.github.com/_sockets/VjI6NTAyMDE5NDc4OjM5OTJiNDNlM2JiNTQ2YjE2NGYzZTExNTZmM2QyYWI1NDZhZTZjZjg4ZWNlMGY0YTM2Y2JlZTU2ZDg0M2VkNzY=--ff968fac2f62059bc1ce7e37e8104a35c72a7283">
  <link rel="sudo-modal" href="/sessions/sudo_modal">

  <meta name="request-id" content="DBC6:6EE7:E36316:1487741:5E95A6C8" data-pjax-transient="true" /><meta name="html-safe-nonce" content="020660e36ac885ef037d8664c1c679debd22067d" data-pjax-transient="true" /><meta name="visitor-payload" content="eyJyZWZlcnJlciI6Imh0dHBzOi8vZ2l0aHViLmNvbS9taWNyb3Jlc2VhcmNoL2FsbGNvbG91cnMvdHJlZS9tYXN0ZXIvc29mdHdhcmUvU1RNMzJGMTAzL3NyYyIsInJlcXVlc3RfaWQiOiJEQkM2OjZFRTc6RTM2MzE2OjE0ODc3NDE6NUU5NUE2QzgiLCJ2aXNpdG9yX2lkIjoiNTc0OTA0ODY0OTA4MjAzMjU1NSIsInJlZ2lvbl9lZGdlIjoiYW1zIiwicmVnaW9uX3JlbmRlciI6ImlhZCJ9" data-pjax-transient="true" /><meta name="visitor-hmac" content="91eafd3d7089d7f269acfd18248fa1fa6f014e96027f38d0ffd0469c0770005c" data-pjax-transient="true" />



  <meta name="github-keyboard-shortcuts" content="repository,source-code" data-pjax-transient="true" />

  

  <meta name="selected-link" value="repo_source" data-pjax-transient>

    <meta name="google-site-verification" content="KT5gs8h0wvaagLKAVWq8bbeNwnZZK1r1XQysX3xurLU">
  <meta name="google-site-verification" content="ZzhVyEFwb7w3e0-uOTltm8Jsck2F5StVihD0exw2fsA">
  <meta name="google-site-verification" content="GXs5KoUUkNCoaAZn7wPN-t01Pywp9M3sEjnt_3_ZWPc">

<meta name="octolytics-host" content="collector.githubapp.com" /><meta name="octolytics-app-id" content="github" /><meta name="octolytics-event-url" content="https://collector.githubapp.com/github-external/browser_event" /><meta name="octolytics-dimension-ga_id" content="" class="js-octo-ga-id" /><meta name="octolytics-actor-id" content="902925" /><meta name="octolytics-actor-login" content="microresearch" /><meta name="octolytics-actor-hash" content="72616c1509b1deacb9c720b52d51bfb622e9bea87bd04f309f5979041b9019e6" />
<meta name="analytics-location" content="/&lt;user-name&gt;/&lt;repo-name&gt;/blob/show" data-pjax-transient="true" />



    <meta name="google-analytics" content="UA-3769691-2">

  <meta class="js-ga-set" name="userId" content="abe0bb28649261b03d8b2ebeefa69209">

<meta class="js-ga-set" name="dimension1" content="Logged In">



  

      <meta name="hostname" content="github.com">
    <meta name="user-login" content="microresearch">

      <meta name="expected-hostname" content="github.com">

      <meta name="js-proxy-site-detection-payload" content="ZDJkZDFiMGRkOTk1MDllMzE0OTlmMzhhMWQ4NWRlOTI1MGNmNGFmZmQwYjgxZjE2YTcyMWJhNDgzNjBkNjRiOXx7InJlbW90ZV9hZGRyZXNzIjoiOTMuMjUzLjEzMS41OSIsInJlcXVlc3RfaWQiOiJEQkM2OjZFRTc6RTM2MzE2OjE0ODc3NDE6NUU5NUE2QzgiLCJ0aW1lc3RhbXAiOjE1ODY4NjU4NzUsImhvc3QiOiJnaXRodWIuY29tIn0=">

    <meta name="enabled-features" content="MARKETPLACE_SOCIAL_PROOF_CUSTOMERS,MARKETPLACE_TRENDING_SOCIAL_PROOF,MARKETPLACE_RECOMMENDATIONS,MARKETPLACE_PENDING_INSTALLATIONS,RELATED_ISSUES,GHE_CLOUD_TRIAL,PAGE_STALE_CHECK">

  <meta http-equiv="x-pjax-version" content="c0ae4cd2555c5fd36251b74235e7683d">
  

      <link href="https://github.com/microresearch/allcolours/commits/master.atom" rel="alternate" title="Recent Commits to allcolours:master" type="application/atom+xml">

  <meta name="go-import" content="github.com/microresearch/allcolours git https://github.com/microresearch/allcolours.git">

  <meta name="octolytics-dimension-user_id" content="902925" /><meta name="octolytics-dimension-user_login" content="microresearch" /><meta name="octolytics-dimension-repository_id" content="127134413" /><meta name="octolytics-dimension-repository_nwo" content="microresearch/allcolours" /><meta name="octolytics-dimension-repository_public" content="true" /><meta name="octolytics-dimension-repository_is_fork" content="false" /><meta name="octolytics-dimension-repository_network_root_id" content="127134413" /><meta name="octolytics-dimension-repository_network_root_nwo" content="microresearch/allcolours" /><meta name="octolytics-dimension-repository_explore_github_marketplace_ci_cta_shown" content="true" />


    <link rel="canonical" href="https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c" data-pjax-transient>


  <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">

  <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">

  <link rel="mask-icon" href="https://github.githubassets.com/pinned-octocat.svg" color="#000000">
  <link rel="alternate icon" class="js-site-favicon" type="image/png" href="https://github.githubassets.com/favicons/favicon.png">
  <link rel="icon" class="js-site-favicon" type="image/svg+xml" href="https://github.githubassets.com/favicons/favicon.svg">

<meta name="theme-color" content="#1e2327">


  <link rel="manifest" href="/manifest.json" crossOrigin="use-credentials">

  </head>

  <body class="logged-in env-production page-responsive page-blob">
    

    <div class="position-relative js-header-wrapper ">
      <a href="#start-of-content" class="p-3 bg-blue text-white show-on-focus js-skip-to-content">Skip to content</a>
      <span class="Progress progress-pjax-loader position-fixed width-full js-pjax-loader-bar">
        <span class="progress-pjax-loader-bar top-0 left-0" style="width: 0%;"></span>
      </span>

      
      



          <header class="Header js-details-container Details flex-wrap flex-lg-nowrap p-responsive" role="banner">

  <div class="Header-item d-none d-lg-flex">
    <a class="Header-link" href="https://github.com/" data-hotkey="g d"
  aria-label="Homepage " data-ga-click="Header, go to dashboard, icon:logo">
  <svg class="octicon octicon-mark-github v-align-middle" height="32" viewBox="0 0 16 16" version="1.1" width="32" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0016 8c0-4.42-3.58-8-8-8z"></path></svg>
</a>

  </div>

  <div class="Header-item d-lg-none">
    <button class="Header-link btn-link js-details-target" type="button" aria-label="Toggle navigation" aria-expanded="false">
      <svg height="24" class="octicon octicon-three-bars" viewBox="0 0 12 16" version="1.1" width="18" aria-hidden="true"><path fill-rule="evenodd" d="M11.41 9H.59C0 9 0 8.59 0 8c0-.59 0-1 .59-1H11.4c.59 0 .59.41.59 1 0 .59 0 1-.59 1h.01zm0-4H.59C0 5 0 4.59 0 4c0-.59 0-1 .59-1H11.4c.59 0 .59.41.59 1 0 .59 0 1-.59 1h.01zM.59 11H11.4c.59 0 .59.41.59 1 0 .59 0 1-.59 1H.59C0 13 0 12.59 0 12c0-.59 0-1 .59-1z"></path></svg>
    </button>
  </div>

  <div class="Header-item Header-item--full flex-column flex-lg-row width-full flex-order-2 flex-lg-order-none mr-0 mr-lg-3 mt-3 mt-lg-0 Details-content--hidden">
      <div class="header-search flex-self-stretch flex-lg-self-auto mr-0 mr-lg-3 mb-3 mb-lg-0 scoped-search site-scoped-search js-site-search position-relative js-jump-to"
  role="combobox"
  aria-owns="jump-to-results"
  aria-label="Search or jump to"
  aria-haspopup="listbox"
  aria-expanded="false"
>
  <div class="position-relative">
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="js-site-search-form" role="search" aria-label="Site" data-scope-type="Repository" data-scope-id="127134413" data-scoped-search-url="/microresearch/allcolours/search" data-unscoped-search-url="/search" action="/microresearch/allcolours/search" accept-charset="UTF-8" method="get">
      <label class="form-control input-sm header-search-wrapper p-0 header-search-wrapper-jump-to position-relative d-flex flex-justify-between flex-items-center js-chromeless-input-container">
        <input type="text"
          class="form-control input-sm header-search-input jump-to-field js-jump-to-field js-site-search-focus js-site-search-field is-clearable"
          data-hotkey="s,/"
          name="q"
          value=""
          placeholder="Search or jump to…"
          data-unscoped-placeholder="Search or jump to…"
          data-scoped-placeholder="Search or jump to…"
          autocapitalize="off"
          aria-autocomplete="list"
          aria-controls="jump-to-results"
          aria-label="Search or jump to…"
          data-jump-to-suggestions-path="/_graphql/GetSuggestedNavigationDestinations"
          spellcheck="false"
          autocomplete="off"
          >
          <input type="hidden" value="DOXv/FsvADZqzhqkD8cmGQbfxYhzC9MKthmdh3CuBADLyZRZofmzBKw2rFKWT60iP5ZmIvyQ6O/6nhYOXON/sw==" data-csrf="true" class="js-data-jump-to-suggestions-path-csrf" />
          <input type="hidden" class="js-site-search-type-field" name="type" >
            <img src="https://github.githubassets.com/images/search-key-slash.svg" alt="" class="mr-2 header-search-key-slash">

            <div class="Box position-absolute overflow-hidden d-none jump-to-suggestions js-jump-to-suggestions-container">
              
<ul class="d-none js-jump-to-suggestions-template-container">
  

<li class="d-flex flex-justify-start flex-items-center p-0 f5 navigation-item js-navigation-item js-jump-to-suggestion" role="option">
  <a tabindex="-1" class="no-underline d-flex flex-auto flex-items-center jump-to-suggestions-path js-jump-to-suggestion-path js-navigation-open p-2" href="">
    <div class="jump-to-octicon js-jump-to-octicon flex-shrink-0 mr-2 text-center d-none">
      <svg height="16" width="16" class="octicon octicon-repo flex-shrink-0 js-jump-to-octicon-repo d-none" title="Repository" aria-label="Repository" viewBox="0 0 12 16" version="1.1" role="img"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-project flex-shrink-0 js-jump-to-octicon-project d-none" title="Project" aria-label="Project" viewBox="0 0 15 16" version="1.1" role="img"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 00-1 1v14a1 1 0 001 1h13a1 1 0 001-1V1a1 1 0 00-1-1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-search flex-shrink-0 js-jump-to-octicon-search d-none" title="Search" aria-label="Search" viewBox="0 0 16 16" version="1.1" role="img"><path fill-rule="evenodd" d="M15.7 13.3l-3.81-3.83A5.93 5.93 0 0013 6c0-3.31-2.69-6-6-6S1 2.69 1 6s2.69 6 6 6c1.3 0 2.48-.41 3.47-1.11l3.83 3.81c.19.2.45.3.7.3.25 0 .52-.09.7-.3a.996.996 0 000-1.41v.01zM7 10.7c-2.59 0-4.7-2.11-4.7-4.7 0-2.59 2.11-4.7 4.7-4.7 2.59 0 4.7 2.11 4.7 4.7 0 2.59-2.11 4.7-4.7 4.7z"></path></svg>
    </div>

    <img class="avatar mr-2 flex-shrink-0 js-jump-to-suggestion-avatar d-none" alt="" aria-label="Team" src="" width="28" height="28">

    <div class="jump-to-suggestion-name js-jump-to-suggestion-name flex-auto overflow-hidden text-left no-wrap css-truncate css-truncate-target">
    </div>

    <div class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none js-jump-to-badge-search">
      <span class="js-jump-to-badge-search-text-default d-none" aria-label="in this repository">
        In this repository
      </span>
      <span class="js-jump-to-badge-search-text-global d-none" aria-label="in all of GitHub">
        All GitHub
      </span>
      <span aria-hidden="true" class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>

    <div aria-hidden="true" class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none d-on-nav-focus js-jump-to-badge-jump">
      Jump to
      <span class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>
  </a>
</li>

</ul>

<ul class="d-none js-jump-to-no-results-template-container">
  <li class="d-flex flex-justify-center flex-items-center f5 d-none js-jump-to-suggestion p-2">
    <span class="text-gray">No suggested jump to results</span>
  </li>
</ul>

<ul id="jump-to-results" role="listbox" class="p-0 m-0 js-navigation-container jump-to-suggestions-results-container js-jump-to-suggestions-results-container">
  

<li class="d-flex flex-justify-start flex-items-center p-0 f5 navigation-item js-navigation-item js-jump-to-scoped-search d-none" role="option">
  <a tabindex="-1" class="no-underline d-flex flex-auto flex-items-center jump-to-suggestions-path js-jump-to-suggestion-path js-navigation-open p-2" href="">
    <div class="jump-to-octicon js-jump-to-octicon flex-shrink-0 mr-2 text-center d-none">
      <svg height="16" width="16" class="octicon octicon-repo flex-shrink-0 js-jump-to-octicon-repo d-none" title="Repository" aria-label="Repository" viewBox="0 0 12 16" version="1.1" role="img"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-project flex-shrink-0 js-jump-to-octicon-project d-none" title="Project" aria-label="Project" viewBox="0 0 15 16" version="1.1" role="img"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 00-1 1v14a1 1 0 001 1h13a1 1 0 001-1V1a1 1 0 00-1-1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-search flex-shrink-0 js-jump-to-octicon-search d-none" title="Search" aria-label="Search" viewBox="0 0 16 16" version="1.1" role="img"><path fill-rule="evenodd" d="M15.7 13.3l-3.81-3.83A5.93 5.93 0 0013 6c0-3.31-2.69-6-6-6S1 2.69 1 6s2.69 6 6 6c1.3 0 2.48-.41 3.47-1.11l3.83 3.81c.19.2.45.3.7.3.25 0 .52-.09.7-.3a.996.996 0 000-1.41v.01zM7 10.7c-2.59 0-4.7-2.11-4.7-4.7 0-2.59 2.11-4.7 4.7-4.7 2.59 0 4.7 2.11 4.7 4.7 0 2.59-2.11 4.7-4.7 4.7z"></path></svg>
    </div>

    <img class="avatar mr-2 flex-shrink-0 js-jump-to-suggestion-avatar d-none" alt="" aria-label="Team" src="" width="28" height="28">

    <div class="jump-to-suggestion-name js-jump-to-suggestion-name flex-auto overflow-hidden text-left no-wrap css-truncate css-truncate-target">
    </div>

    <div class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none js-jump-to-badge-search">
      <span class="js-jump-to-badge-search-text-default d-none" aria-label="in this repository">
        In this repository
      </span>
      <span class="js-jump-to-badge-search-text-global d-none" aria-label="in all of GitHub">
        All GitHub
      </span>
      <span aria-hidden="true" class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>

    <div aria-hidden="true" class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none d-on-nav-focus js-jump-to-badge-jump">
      Jump to
      <span class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>
  </a>
</li>

  

<li class="d-flex flex-justify-start flex-items-center p-0 f5 navigation-item js-navigation-item js-jump-to-global-search d-none" role="option">
  <a tabindex="-1" class="no-underline d-flex flex-auto flex-items-center jump-to-suggestions-path js-jump-to-suggestion-path js-navigation-open p-2" href="">
    <div class="jump-to-octicon js-jump-to-octicon flex-shrink-0 mr-2 text-center d-none">
      <svg height="16" width="16" class="octicon octicon-repo flex-shrink-0 js-jump-to-octicon-repo d-none" title="Repository" aria-label="Repository" viewBox="0 0 12 16" version="1.1" role="img"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-project flex-shrink-0 js-jump-to-octicon-project d-none" title="Project" aria-label="Project" viewBox="0 0 15 16" version="1.1" role="img"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 00-1 1v14a1 1 0 001 1h13a1 1 0 001-1V1a1 1 0 00-1-1z"></path></svg>
      <svg height="16" width="16" class="octicon octicon-search flex-shrink-0 js-jump-to-octicon-search d-none" title="Search" aria-label="Search" viewBox="0 0 16 16" version="1.1" role="img"><path fill-rule="evenodd" d="M15.7 13.3l-3.81-3.83A5.93 5.93 0 0013 6c0-3.31-2.69-6-6-6S1 2.69 1 6s2.69 6 6 6c1.3 0 2.48-.41 3.47-1.11l3.83 3.81c.19.2.45.3.7.3.25 0 .52-.09.7-.3a.996.996 0 000-1.41v.01zM7 10.7c-2.59 0-4.7-2.11-4.7-4.7 0-2.59 2.11-4.7 4.7-4.7 2.59 0 4.7 2.11 4.7 4.7 0 2.59-2.11 4.7-4.7 4.7z"></path></svg>
    </div>

    <img class="avatar mr-2 flex-shrink-0 js-jump-to-suggestion-avatar d-none" alt="" aria-label="Team" src="" width="28" height="28">

    <div class="jump-to-suggestion-name js-jump-to-suggestion-name flex-auto overflow-hidden text-left no-wrap css-truncate css-truncate-target">
    </div>

    <div class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none js-jump-to-badge-search">
      <span class="js-jump-to-badge-search-text-default d-none" aria-label="in this repository">
        In this repository
      </span>
      <span class="js-jump-to-badge-search-text-global d-none" aria-label="in all of GitHub">
        All GitHub
      </span>
      <span aria-hidden="true" class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>

    <div aria-hidden="true" class="border rounded-1 flex-shrink-0 bg-gray px-1 text-gray-light ml-1 f6 d-none d-on-nav-focus js-jump-to-badge-jump">
      Jump to
      <span class="d-inline-block ml-1 v-align-middle">↵</span>
    </div>
  </a>
</li>


    <li class="d-flex flex-justify-center flex-items-center p-0 f5 js-jump-to-suggestion">
      <img src="https://github.githubassets.com/images/spinners/octocat-spinner-128.gif" alt="Octocat Spinner Icon" class="m-2" width="28">
    </li>
</ul>

            </div>
      </label>
</form>  </div>
</div>


    <nav class="d-flex flex-column flex-lg-row flex-self-stretch flex-lg-self-auto" aria-label="Global">
    <a class="Header-link d-block d-lg-none py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15" data-ga-click="Header, click, Nav menu - item:dashboard:user" aria-label="Dashboard" href="/dashboard">
      Dashboard
</a>
  <a class="js-selected-navigation-item Header-link  mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15" data-hotkey="g p" data-ga-click="Header, click, Nav menu - item:pulls context:user" aria-label="Pull requests you created" data-selected-links="/pulls /pulls/assigned /pulls/mentioned /pulls" href="/pulls">
    Pull requests
</a>
  <a class="js-selected-navigation-item Header-link  mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15" data-hotkey="g i" data-ga-click="Header, click, Nav menu - item:issues context:user" aria-label="Issues you created" data-selected-links="/issues /issues/assigned /issues/mentioned /issues" href="/issues">
    Issues
</a>

    <div class="mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15">
      <a class="js-selected-navigation-item Header-link" data-ga-click="Header, click, Nav menu - item:marketplace context:user" data-octo-click="marketplace_click" data-octo-dimensions="location:nav_bar" data-selected-links=" /marketplace" href="/marketplace">
        Marketplace
</a>      

    </div>

  <a class="js-selected-navigation-item Header-link  mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15" data-ga-click="Header, click, Nav menu - item:explore" data-selected-links="/explore /trending /trending/developers /integrations /integrations/feature/code /integrations/feature/collaborate /integrations/feature/ship showcases showcases_search showcases_landing /explore" href="/explore">
    Explore
</a>


    <a class="Header-link d-block d-lg-none mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15" href="https://github.com/microresearch">
      <img class="avatar" height="20" width="20" alt="@microresearch" src="https://avatars2.githubusercontent.com/u/902925?s=60&amp;u=d00aa4c74b09e3506476bd614e3533f84637939a&amp;v=4" />
      microresearch
</a>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form action="/logout" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="vbM9wJIpO06ikUSMCbtRL4h4pEv+jU+kSPXv5R+XYYZ+FHppOPRI3WIlz9a2aXW7irIXvHxtRvb4fFTVhm7NZQ==" />
      <button type="submit" class="Header-link mr-0 mr-lg-3 py-2 py-lg-0 border-top border-lg-top-0 border-white-fade-15 d-lg-none btn-link d-block width-full text-left" data-ga-click="Header, sign out, icon:logout" style="padding-left: 2px;">
        <svg class="octicon octicon-sign-out v-align-middle" viewBox="0 0 16 17" version="1.1" width="16" height="17" aria-hidden="true"><path fill-rule="evenodd" d="M12 9V7H8V5h4V3l4 3-4 3zm-2 3H6V3L2 1h8v3h1V1c0-.55-.45-1-1-1H1C.45 0 0 .45 0 1v11.38c0 .39.22.73.55.91L6 16.01V13h4c.55 0 1-.45 1-1V8h-1v4z"></path></svg>
        Sign out
      </button>
</form></nav>

  </div>

  <div class="Header-item Header-item--full flex-justify-center d-lg-none position-relative">
    <div class="css-truncate css-truncate-target width-fit position-absolute left-0 right-0 text-center">
                <svg class="octicon octicon-repo" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"></path></svg>
    <a class="Header-link" href="/microresearch">microresearch</a>
    /
    <a class="Header-link" href="/microresearch/allcolours">allcolours</a>

</div>
  </div>

  <div class="Header-item mr-0 mr-lg-3 flex-order-1 flex-lg-order-none">
    

    <a aria-label="You have no unread notifications" class="Header-link notification-indicator position-relative tooltipped tooltipped-sw js-socket-channel js-notification-indicator" data-hotkey="g n" data-ga-click="Header, go to notifications, icon:read" data-channel="notification-changed:902925" href="/notifications/beta">
        <span class="js-indicator-modifier mail-status "></span>
        <svg class="octicon octicon-bell" viewBox="0 0 15 16" version="1.1" width="15" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 12v1H0v-1l.73-.58c.77-.77.81-2.55 1.19-4.42C2.69 3.23 6 2 6 2c0-.55.45-1 1-1s1 .45 1 1c0 0 3.39 1.23 4.16 5 .38 1.88.42 3.66 1.19 4.42l.66.58H14zm-7 4c1.11 0 2-.89 2-2H5c0 1.11.89 2 2 2z"></path></svg>
</a>
  </div>


  <div class="Header-item position-relative d-none d-lg-flex">
    <details class="details-overlay details-reset">
  <summary class="Header-link"
      aria-label="Create new…"
      data-ga-click="Header, create new, icon:add">
    <svg class="octicon octicon-plus" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 9H7v5H5V9H0V7h5V2h2v5h5v2z"></path></svg> <span class="dropdown-caret"></span>
  </summary>
  <details-menu class="dropdown-menu dropdown-menu-sw">
    
<a role="menuitem" class="dropdown-item" href="/new" data-ga-click="Header, create new repository">
  New repository
</a>

  <a role="menuitem" class="dropdown-item" href="/new/import" data-ga-click="Header, import a repository">
    Import repository
  </a>

<a role="menuitem" class="dropdown-item" href="https://gist.github.com/" data-ga-click="Header, create new gist">
  New gist
</a>

  <a role="menuitem" class="dropdown-item" href="/organizations/new" data-ga-click="Header, create new organization">
    New organization
  </a>


  <div role="none" class="dropdown-divider"></div>
  <div class="dropdown-header">
    <span title="microresearch/allcolours">This repository</span>
  </div>
    <a role="menuitem" class="dropdown-item" href="/microresearch/allcolours/issues/new/choose" data-ga-click="Header, create new issue" data-skip-pjax>
      New issue
    </a>


  </details-menu>
</details>

  </div>

  <div class="Header-item position-relative mr-0 d-none d-lg-flex">
    
  <details class="details-overlay details-reset js-feature-preview-indicator-container" data-feature-preview-indicator-src="/users/microresearch/feature_preview/indicator_check">

  <summary class="Header-link"
    aria-label="View profile and more"
    data-ga-click="Header, show menu, icon:avatar">
    <img class="avatar " alt="@microresearch" width="20" height="20" src="https://avatars2.githubusercontent.com/u/902925?s=60&amp;u=d00aa4c74b09e3506476bd614e3533f84637939a&amp;v=4">


      <span class="feature-preview-indicator js-feature-preview-indicator" hidden></span>
    <span class="dropdown-caret"></span>
  </summary>
  <details-menu class="dropdown-menu dropdown-menu-sw mt-2" style="width: 180px">
    <div class="header-nav-current-user css-truncate"><a role="menuitem" class="no-underline user-profile-link px-3 pt-2 pb-2 mb-n2 mt-n1 d-block" href="/microresearch" data-ga-click="Header, go to profile, text:Signed in as">Signed in as <strong class="css-truncate-target">microresearch</strong></a></div>
    <div role="none" class="dropdown-divider"></div>

      <div class="pl-3 pr-3 f6 user-status-container js-user-status-context pb-1" data-url="/users/status?compact=1&amp;link_mentions=0&amp;truncate=1">
        
<div class="js-user-status-container
    user-status-compact rounded-1 px-2 py-1 mt-2
    border
  " data-team-hovercards-enabled>
  <details class="js-user-status-details details-reset details-overlay details-overlay-dark">
    <summary class="btn-link btn-block link-gray no-underline js-toggle-user-status-edit toggle-user-status-edit "
      role="menuitem" data-hydro-click="{&quot;event_type&quot;:&quot;user_profile.click&quot;,&quot;payload&quot;:{&quot;profile_user_id&quot;:902925,&quot;target&quot;:&quot;EDIT_USER_STATUS&quot;,&quot;user_id&quot;:902925,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;}}" data-hydro-click-hmac="a19c6d6380bd30c019baeffad96154a9907785a1944b81cde9cf5d160d37e5e3">
      <div class="d-flex">
        <div class="f6 lh-condensed user-status-header
          d-inline-block v-align-middle
            user-status-emoji-only-header circle
            pr-2
"
            style="max-width: 29px"
          >
          <div class="user-status-emoji-container flex-shrink-0 mr-1 mt-1 lh-condensed-ultra v-align-bottom" style="">
            <svg class="octicon octicon-smiley" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8s3.58 8 8 8 8-3.58 8-8-3.58-8-8-8zm4.81 12.81a6.72 6.72 0 01-2.17 1.45c-.83.36-1.72.53-2.64.53-.92 0-1.81-.17-2.64-.53-.81-.34-1.55-.83-2.17-1.45a6.773 6.773 0 01-1.45-2.17A6.59 6.59 0 011.21 8c0-.92.17-1.81.53-2.64.34-.81.83-1.55 1.45-2.17.62-.62 1.36-1.11 2.17-1.45A6.59 6.59 0 018 1.21c.92 0 1.81.17 2.64.53.81.34 1.55.83 2.17 1.45.62.62 1.11 1.36 1.45 2.17.36.83.53 1.72.53 2.64 0 .92-.17 1.81-.53 2.64-.34.81-.83 1.55-1.45 2.17zM4 6.8v-.59c0-.66.53-1.19 1.2-1.19h.59c.66 0 1.19.53 1.19 1.19v.59c0 .67-.53 1.2-1.19 1.2H5.2C4.53 8 4 7.47 4 6.8zm5 0v-.59c0-.66.53-1.19 1.2-1.19h.59c.66 0 1.19.53 1.19 1.19v.59c0 .67-.53 1.2-1.19 1.2h-.59C9.53 8 9 7.47 9 6.8zm4 3.2c-.72 1.88-2.91 3-5 3s-4.28-1.13-5-3c-.14-.39.23-1 .66-1h8.59c.41 0 .89.61.75 1z"></path></svg>
          </div>
        </div>
        <div class="
          d-inline-block v-align-middle
          
          
           css-truncate css-truncate-target 
           user-status-message-wrapper f6"
           style="line-height: 20px;" >
          <div class="d-inline-block text-gray-dark v-align-text-top text-left">
              <span class="text-gray ml-2">Set status</span>
          </div>
        </div>
      </div>
    </summary>
    <details-dialog class="details-dialog rounded-1 anim-fade-in fast Box Box--overlay" role="dialog" tabindex="-1">
      <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="position-relative flex-auto js-user-status-form" action="/users/status?compact=1&amp;link_mentions=0&amp;truncate=1" accept-charset="UTF-8" method="post"><input type="hidden" name="_method" value="put" /><input type="hidden" name="authenticity_token" value="jgrPf4fn3z0Ms4J/b81bJCuWSgL9+rr9umkfH3cyYqmXnu1do7oBxOw4uZR25pr8FxoYeLe+/f/y06Q5g0T1DA==" />
        <div class="Box-header bg-gray border-bottom p-3">
          <button class="Box-btn-octicon js-toggle-user-status-edit btn-octicon float-right" type="reset" aria-label="Close dialog" data-close-dialog>
            <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48L7.48 8z"></path></svg>
          </button>
          <h3 class="Box-title f5 text-bold text-gray-dark">Edit status</h3>
        </div>
        <input type="hidden" name="emoji" class="js-user-status-emoji-field" value="">
        <input type="hidden" name="organization_id" class="js-user-status-org-id-field" value="">
        <div class="px-3 py-2 text-gray-dark">
          <div class="js-characters-remaining-container position-relative mt-2">
            <div class="input-group d-table form-group my-0 js-user-status-form-group">
              <span class="input-group-button d-table-cell v-align-middle" style="width: 1%">
                <button type="button" aria-label="Choose an emoji" class="btn-outline btn js-toggle-user-status-emoji-picker btn-open-emoji-picker p-0">
                  <span class="js-user-status-original-emoji" hidden></span>
                  <span class="js-user-status-custom-emoji"></span>
                  <span class="js-user-status-no-emoji-icon" >
                    <svg class="octicon octicon-smiley" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8s3.58 8 8 8 8-3.58 8-8-3.58-8-8-8zm4.81 12.81a6.72 6.72 0 01-2.17 1.45c-.83.36-1.72.53-2.64.53-.92 0-1.81-.17-2.64-.53-.81-.34-1.55-.83-2.17-1.45a6.773 6.773 0 01-1.45-2.17A6.59 6.59 0 011.21 8c0-.92.17-1.81.53-2.64.34-.81.83-1.55 1.45-2.17.62-.62 1.36-1.11 2.17-1.45A6.59 6.59 0 018 1.21c.92 0 1.81.17 2.64.53.81.34 1.55.83 2.17 1.45.62.62 1.11 1.36 1.45 2.17.36.83.53 1.72.53 2.64 0 .92-.17 1.81-.53 2.64-.34.81-.83 1.55-1.45 2.17zM4 6.8v-.59c0-.66.53-1.19 1.2-1.19h.59c.66 0 1.19.53 1.19 1.19v.59c0 .67-.53 1.2-1.19 1.2H5.2C4.53 8 4 7.47 4 6.8zm5 0v-.59c0-.66.53-1.19 1.2-1.19h.59c.66 0 1.19.53 1.19 1.19v.59c0 .67-.53 1.2-1.19 1.2h-.59C9.53 8 9 7.47 9 6.8zm4 3.2c-.72 1.88-2.91 3-5 3s-4.28-1.13-5-3c-.14-.39.23-1 .66-1h8.59c.41 0 .89.61.75 1z"></path></svg>
                  </span>
                </button>
              </span>
              <text-expander keys=": @" data-mention-url="/autocomplete/user-suggestions" data-emoji-url="/autocomplete/emoji">
                <input
                  type="text"
                  autocomplete="off"
                  data-no-org-url="/autocomplete/user-suggestions"
                  data-org-url="/suggestions?mention_suggester=1"
                  data-maxlength="80"
                  class="d-table-cell width-full form-control js-user-status-message-field js-characters-remaining-field"
                  placeholder="What's happening?"
                  name="message"
                  value=""
                  aria-label="What is your current status?">
              </text-expander>
              <div class="error">Could not update your status, please try again.</div>
            </div>
            <div style="margin-left: 53px" class="my-1 text-small label-characters-remaining js-characters-remaining" data-suffix="remaining" hidden>
              80 remaining
            </div>
          </div>
          <include-fragment class="js-user-status-emoji-picker" data-url="/users/status/emoji"></include-fragment>
          <div class="overflow-auto ml-n3 mr-n3 px-3 border-bottom" style="max-height: 33vh">
            <div class="user-status-suggestions js-user-status-suggestions collapsed overflow-hidden">
              <h4 class="f6 text-normal my-3">Suggestions:</h4>
              <div class="mx-3 mt-2 clearfix">
                  <div class="float-left col-6">
                      <button type="button" value=":palm_tree:" class="d-flex flex-items-baseline flex-items-stretch lh-condensed f6 btn-link link-gray no-underline js-predefined-user-status mb-1">
                        <div class="emoji-status-width mr-2 v-align-middle js-predefined-user-status-emoji">
                          <g-emoji alias="palm_tree" fallback-src="https://github.githubassets.com/images/icons/emoji/unicode/1f334.png">🌴</g-emoji>
                        </div>
                        <div class="d-flex flex-items-center no-underline js-predefined-user-status-message ws-normal text-left" style="border-left: 1px solid transparent">
                          On vacation
                        </div>
                      </button>
                      <button type="button" value=":face_with_thermometer:" class="d-flex flex-items-baseline flex-items-stretch lh-condensed f6 btn-link link-gray no-underline js-predefined-user-status mb-1">
                        <div class="emoji-status-width mr-2 v-align-middle js-predefined-user-status-emoji">
                          <g-emoji alias="face_with_thermometer" fallback-src="https://github.githubassets.com/images/icons/emoji/unicode/1f912.png">🤒</g-emoji>
                        </div>
                        <div class="d-flex flex-items-center no-underline js-predefined-user-status-message ws-normal text-left" style="border-left: 1px solid transparent">
                          Out sick
                        </div>
                      </button>
                  </div>
                  <div class="float-left col-6">
                      <button type="button" value=":house:" class="d-flex flex-items-baseline flex-items-stretch lh-condensed f6 btn-link link-gray no-underline js-predefined-user-status mb-1">
                        <div class="emoji-status-width mr-2 v-align-middle js-predefined-user-status-emoji">
                          <g-emoji alias="house" fallback-src="https://github.githubassets.com/images/icons/emoji/unicode/1f3e0.png">🏠</g-emoji>
                        </div>
                        <div class="d-flex flex-items-center no-underline js-predefined-user-status-message ws-normal text-left" style="border-left: 1px solid transparent">
                          Working from home
                        </div>
                      </button>
                      <button type="button" value=":dart:" class="d-flex flex-items-baseline flex-items-stretch lh-condensed f6 btn-link link-gray no-underline js-predefined-user-status mb-1">
                        <div class="emoji-status-width mr-2 v-align-middle js-predefined-user-status-emoji">
                          <g-emoji alias="dart" fallback-src="https://github.githubassets.com/images/icons/emoji/unicode/1f3af.png">🎯</g-emoji>
                        </div>
                        <div class="d-flex flex-items-center no-underline js-predefined-user-status-message ws-normal text-left" style="border-left: 1px solid transparent">
                          Focusing
                        </div>
                      </button>
                  </div>
              </div>
            </div>
            <div class="user-status-limited-availability-container">
              <div class="form-checkbox my-0">
                <input type="checkbox" name="limited_availability" value="1" class="js-user-status-limited-availability-checkbox" data-default-message="I may be slow to respond." aria-describedby="limited-availability-help-text-truncate-true-compact-true" id="limited-availability-truncate-true-compact-true">
                <label class="d-block f5 text-gray-dark mb-1" for="limited-availability-truncate-true-compact-true">
                  Busy
                </label>
                <p class="note" id="limited-availability-help-text-truncate-true-compact-true">
                  When others mention you, assign you, or request your review,
                  GitHub will let them know that you have limited availability.
                </p>
              </div>
            </div>
          </div>
          <div class="d-inline-block f5 mr-2 pt-3 pb-2" >
  <div class="d-inline-block mr-1">
    Clear status
  </div>

  <details class="js-user-status-expire-drop-down f6 dropdown details-reset details-overlay d-inline-block mr-2">
    <summary class="f5 btn-link link-gray-dark border px-2 py-1 rounded-1" aria-haspopup="true">
      <div class="js-user-status-expiration-interval-selected d-inline-block v-align-baseline">
        Never
      </div>
      <div class="dropdown-caret"></div>
    </summary>

    <ul class="dropdown-menu dropdown-menu-se pl-0 overflow-auto" style="width: 220px; max-height: 15.5em">
      <li>
        <button type="button" class="btn-link dropdown-item js-user-status-expire-button ws-normal" title="Never">
          <span class="d-inline-block text-bold mb-1">Never</span>
          <div class="f6 lh-condensed">Keep this status until you clear your status or edit your status.</div>
        </button>
      </li>
      <li class="dropdown-divider" role="none"></li>
        <li>
          <button type="button" class="btn-link dropdown-item ws-normal js-user-status-expire-button" title="in 30 minutes" value="2020-04-14T14:34:35+02:00">
            in 30 minutes
          </button>
        </li>
        <li>
          <button type="button" class="btn-link dropdown-item ws-normal js-user-status-expire-button" title="in 1 hour" value="2020-04-14T15:04:35+02:00">
            in 1 hour
          </button>
        </li>
        <li>
          <button type="button" class="btn-link dropdown-item ws-normal js-user-status-expire-button" title="in 4 hours" value="2020-04-14T18:04:35+02:00">
            in 4 hours
          </button>
        </li>
        <li>
          <button type="button" class="btn-link dropdown-item ws-normal js-user-status-expire-button" title="today" value="2020-04-14T23:59:59+02:00">
            today
          </button>
        </li>
        <li>
          <button type="button" class="btn-link dropdown-item ws-normal js-user-status-expire-button" title="this week" value="2020-04-19T23:59:59+02:00">
            this week
          </button>
        </li>
    </ul>
  </details>
  <input class="js-user-status-expiration-date-input" type="hidden" name="expires_at" value="">
</div>

          <include-fragment class="js-user-status-org-picker" data-url="/users/status/organizations"></include-fragment>
        </div>
        <div class="d-flex flex-items-center flex-justify-between p-3 border-top">
          <button type="submit" disabled class="width-full btn btn-primary mr-2 js-user-status-submit">
            Set status
          </button>
          <button type="button" disabled class="width-full js-clear-user-status-button btn ml-2 ">
            Clear status
          </button>
        </div>
</form>    </details-dialog>
  </details>
</div>

      </div>
      <div role="none" class="dropdown-divider"></div>

    <a role="menuitem" class="dropdown-item" href="/microresearch" data-ga-click="Header, go to profile, text:your profile">Your profile</a>

    <a role="menuitem" class="dropdown-item" href="/microresearch?tab=repositories" data-ga-click="Header, go to repositories, text:your repositories">Your repositories</a>

    <a role="menuitem" class="dropdown-item" href="/microresearch?tab=projects" data-ga-click="Header, go to projects, text:your projects">Your projects</a>

    <a role="menuitem" class="dropdown-item" href="/microresearch?tab=stars" data-ga-click="Header, go to starred repos, text:your stars">Your stars</a>
      <a role="menuitem" class="dropdown-item" href="https://gist.github.com/mine" data-ga-click="Header, your gists, text:your gists">Your gists</a>





    <div role="none" class="dropdown-divider"></div>
      
<div id="feature-enrollment-toggle" class="hide-sm hide-md feature-preview-details position-relative">
  <button
    type="button"
    class="dropdown-item btn-link"
    role="menuitem"
    data-feature-preview-trigger-url="/users/microresearch/feature_previews"
    data-feature-preview-close-details="{&quot;event_type&quot;:&quot;feature_preview.clicks.close_modal&quot;,&quot;payload&quot;:{&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}"
    data-feature-preview-close-hmac="a147b4d1ff14e669f9881b2ca3a4a71f373d1dd16019b5e100463bb00ce84533"
    data-hydro-click="{&quot;event_type&quot;:&quot;feature_preview.clicks.open_modal&quot;,&quot;payload&quot;:{&quot;link_location&quot;:&quot;user_dropdown&quot;,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}"
    data-hydro-click-hmac="8c4c6358a199bc5c6610e49212e05e3b1883f3be670bc42abcf2046a2ddc0eac"
  >
    Feature preview
  </button>
    <span class="feature-preview-indicator js-feature-preview-indicator" hidden></span>
</div>

    <a role="menuitem" class="dropdown-item" href="https://help.github.com" data-ga-click="Header, go to help, text:help">Help</a>
    <a role="menuitem" class="dropdown-item" href="/settings/profile" data-ga-click="Header, go to settings, icon:settings">Settings</a>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="logout-form" action="/logout" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="eBxO7XxDvtdqc0SpO310/T8uWH+WCD7zYYIDgAUEf9u7uwlE1p7NRKrHz/OEr1BpPeTriBToN6HRC7iwnP3TOA==" />
      
      <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout" role="menuitem">
        Sign out
      </button>
      <input type="text" name="required_field_8665" hidden="hidden" class="form-control" /><input type="hidden" name="timestamp" value="1586865875063" class="form-control" /><input type="hidden" name="timestamp_secret" value="b8f4260fc4f3e36c3e262578ab2635610ffd191269876cb062c583c9068c31eb" class="form-control" />
</form>  </details-menu>
</details>

  </div>

</header>

        

    </div>

  <div id="start-of-content" class="show-on-focus"></div>


    <div id="js-flash-container">


  <template class="js-flash-template">
    <div class="flash flash-full  js-flash-template-container">
  <div class="container-lg px-2" >
    <button class="flash-close js-flash-close" type="button" aria-label="Dismiss this message">
      <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48L7.48 8z"></path></svg>
    </button>
    
      <div class="js-flash-template-message"></div>

  </div>
</div>
  </template>
</div>


      

  <include-fragment class="js-notification-shelf-include-fragment" data-base-src="https://github.com/notifications/beta/shelf"></include-fragment>




  <div class="application-main " data-commit-hovercards-enabled>
        <div itemscope itemtype="http://schema.org/SoftwareSourceCode" class="">
    <main  >
      

  


      <div class="border-bottom shelf intro-shelf js-notice mb-0 pb-4">
  <div class="width-full container">
    <div class="width-full mx-auto shelf-content">
      <h2 class="shelf-title">Learn Git and GitHub without any code!</h2>
      <p class="shelf-lead">
          Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.
      </p>
      <a class="btn btn-primary shelf-cta" target="_blank" data-hydro-click="{&quot;event_type&quot;:&quot;repository.click&quot;,&quot;payload&quot;:{&quot;target&quot;:&quot;READ_GUIDE&quot;,&quot;repository_id&quot;:127134413,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}" data-hydro-click-hmac="c952802524cf002222fbca2cafcf3d8888ef9f3187cd464ed0556ff0d86fe75d" href="https://guides.github.com/activities/hello-world/">Read the guide</a>
    </div>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="shelf-dismiss js-notice-dismiss" action="/dashboard/dismiss_bootcamp" accept-charset="UTF-8" method="post"><input type="hidden" name="_method" value="delete" /><input type="hidden" name="authenticity_token" value="ou4nuVRD96jabH0zlHbeX+5QntGWHdYRYXOvqhqwvSvTlda3QvTXIcbCJeShhJcqMqs/S2HQGGIeLVJmp9QLAA==" />
      <button name="button" type="submit" class="mr-1 close-button tooltipped tooltipped-w" aria-label="Hide this notice forever" data-hydro-click="{&quot;event_type&quot;:&quot;repository.click&quot;,&quot;payload&quot;:{&quot;target&quot;:&quot;DISMISS_BANNER&quot;,&quot;repository_id&quot;:127134413,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}" data-hydro-click-hmac="4d00bbb443dc05384f03ec1b925afd1beaf274b398f17e6b48b9715e9d2b7bef">
        <svg aria-label="Hide this notice forever" class="octicon octicon-x v-align-text-top" viewBox="0 0 12 16" version="1.1" width="12" height="16" role="img"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48L7.48 8z"></path></svg>
</button></form>  </div>
</div>










  <div class="pagehead repohead hx_repohead readability-menu bg-gray-light pb-0 pt-0 pt-lg-3">

    <div class="d-flex container-lg mb-4 p-responsive d-none d-lg-flex">

      <div class="flex-auto min-width-0 width-fit mr-3">
        <h1 class="public  d-flex flex-wrap flex-items-center break-word float-none ">
  <span class="flex-self-stretch" style="margin-top: -2px;">
      <svg class="octicon octicon-repo" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"></path></svg>
  </span>
  <span class="author ml-2 flex-self-stretch" itemprop="author">
    <a class="url fn" rel="author" data-hovercard-type="user" data-hovercard-url="/users/microresearch/hovercard" data-octo-click="hovercard-link-click" data-octo-dimensions="link_type:self" href="/microresearch">microresearch</a>
  </span>
  <span class="path-divider flex-self-stretch">/</span>
  <strong itemprop="name" class="mr-2 flex-self-stretch">
    <a data-pjax="#js-repo-pjax-container" href="/microresearch/allcolours">allcolours</a>
  </strong>
  
</h1>


      </div>

      <ul class="pagehead-actions flex-shrink-0 " >



    <li hidden>
      <include-fragment src="/microresearch/allcolours/used_by_count" accept="text/fragment+html">
</include-fragment>
    </li>

  <li>
    
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form data-remote="true" class="clearfix js-social-form js-social-container" action="/notifications/subscribe" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="yGQZAUjNl6+hhDNX5xZs3CSwxRopg3oMK01oO3JX4bEayjtCrJ8Num4wfLvF8Oae8/i1QvI3hKTFsD415DrdVQ==" />      <input type="hidden" name="repository_id" value="127134413">

      <details class="details-reset details-overlay select-menu float-left">
        <summary class="select-menu-button float-left btn btn-sm btn-with-count" data-hydro-click="{&quot;event_type&quot;:&quot;repository.click&quot;,&quot;payload&quot;:{&quot;target&quot;:&quot;WATCH_BUTTON&quot;,&quot;repository_id&quot;:127134413,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}" data-hydro-click-hmac="35f17bf722637c278e261319cd455c8a4e77ace7bb43c4a5c304e8aa59f3ea2d" data-ga-click="Repository, click Watch settings, action:blob#show">          <span data-menu-button>
              <svg class="octicon octicon-eye v-align-text-bottom" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path></svg>
              Unwatch
          </span>
</summary>        <details-menu
          class="select-menu-modal position-absolute mt-5"
          style="z-index: 99;">
          <div class="select-menu-header">
            <span class="select-menu-title">Notifications</span>
          </div>
          <div class="select-menu-list">
            <button type="submit" name="do" value="included" class="select-menu-item width-full" aria-checked="false" role="menuitemradio">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5L12 5z"></path></svg>
              <div class="select-menu-item-text">
                <span class="select-menu-item-heading">Not watching</span>
                <span class="description">Be notified only when participating or @mentioned.</span>
                <span class="hidden-select-button-text" data-menu-button-contents>
                  <svg class="octicon octicon-eye v-align-text-bottom" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path></svg>
                  Watch
                </span>
              </div>
            </button>

            <button type="submit" name="do" value="release_only" class="select-menu-item width-full" aria-checked="false" role="menuitemradio">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5L12 5z"></path></svg>
              <div class="select-menu-item-text">
                <span class="select-menu-item-heading">Releases only</span>
                <span class="description">Be notified of new releases, and when participating or @mentioned.</span>
                <span class="hidden-select-button-text" data-menu-button-contents>
                  <svg class="octicon octicon-eye v-align-text-bottom" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path></svg>
                  Unwatch releases
                </span>
              </div>
            </button>

            <button type="submit" name="do" value="subscribed" class="select-menu-item width-full" aria-checked="true" role="menuitemradio">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5L12 5z"></path></svg>
              <div class="select-menu-item-text">
                <span class="select-menu-item-heading">Watching</span>
                <span class="description">Be notified of all conversations.</span>
                <span class="hidden-select-button-text" data-menu-button-contents>
                  <svg class="octicon octicon-eye v-align-text-bottom" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path></svg>
                  Unwatch
                </span>
              </div>
            </button>

            <button type="submit" name="do" value="ignore" class="select-menu-item width-full" aria-checked="false" role="menuitemradio">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5L12 5z"></path></svg>
              <div class="select-menu-item-text">
                <span class="select-menu-item-heading">Ignoring</span>
                <span class="description">Never be notified.</span>
                <span class="hidden-select-button-text" data-menu-button-contents>
                  <svg class="octicon octicon-mute v-align-text-bottom" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 2.81v10.38c0 .67-.81 1-1.28.53L3 10H1c-.55 0-1-.45-1-1V7c0-.55.45-1 1-1h2l3.72-3.72C7.19 1.81 8 2.14 8 2.81zm7.53 3.22l-1.06-1.06-1.97 1.97-1.97-1.97-1.06 1.06L11.44 8 9.47 9.97l1.06 1.06 1.97-1.97 1.97 1.97 1.06-1.06L13.56 8l1.97-1.97z"></path></svg>
                  Stop ignoring
                </span>
              </div>
            </button>
          </div>
        </details-menu>
      </details>
        <a class="social-count js-social-count"
          href="/microresearch/allcolours/watchers"
          aria-label="1 user is watching this repository">
          1
        </a>
</form>
  </li>

  <li>
      <div class="js-toggler-container js-social-container starring-container ">
    <form class="starred js-social-form" action="/microresearch/allcolours/unstar" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="BFtLxqXinRGjvIhIyFGDfKbL5LCbmGRfyV9HznMHurwI0L+OSxOWXDQ0dwhMPRI+qWmy9faPGZP7vMfhmfx9yw==" />
      <input type="hidden" name="context" value="repository"></input>
      <button type="submit" class="btn btn-sm btn-with-count js-toggler-target" aria-label="Unstar this repository" title="Unstar microresearch/allcolours" data-hydro-click="{&quot;event_type&quot;:&quot;repository.click&quot;,&quot;payload&quot;:{&quot;target&quot;:&quot;UNSTAR_BUTTON&quot;,&quot;repository_id&quot;:127134413,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}" data-hydro-click-hmac="d6a7fbafb6d1c47779d5e9344395c2809daf47c75a328c0bc3cbc6f3ebd2ef71" data-ga-click="Repository, click unstar button, action:blob#show; text:Unstar">        <svg height="16" class="octicon octicon-star v-align-text-bottom" vertical_align="text_bottom" viewBox="0 0 14 16" version="1.1" width="14" aria-hidden="true"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74L14 6z"></path></svg>

        Unstar
</button>        <a class="social-count js-social-count" href="/microresearch/allcolours/stargazers"
           aria-label="0 users starred this repository">
           0
        </a>
</form>
    <form class="unstarred js-social-form" action="/microresearch/allcolours/star" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="RwrFud2BdMBsnu8CscrDn6+Ja1J7UsAOIi0Pvqof/5iWMp2UQ7EvtQK2b/yj9FWFTHtkH42e8GAfUDLLMSgoiw==" />
      <input type="hidden" name="context" value="repository"></input>
      <button type="submit" class="btn btn-sm btn-with-count js-toggler-target" aria-label="Unstar this repository" title="Star microresearch/allcolours" data-hydro-click="{&quot;event_type&quot;:&quot;repository.click&quot;,&quot;payload&quot;:{&quot;target&quot;:&quot;STAR_BUTTON&quot;,&quot;repository_id&quot;:127134413,&quot;originating_url&quot;:&quot;https://github.com/microresearch/allcolours/blob/master/software/STM32F103/src/stm32f10x_it.c&quot;,&quot;user_id&quot;:902925}}" data-hydro-click-hmac="efcba820b720925b78311a82f3a5eabea991fb9b5eea74731b31f4e1b88a8e6b" data-ga-click="Repository, click star button, action:blob#show; text:Star">        <svg height="16" class="octicon octicon-star v-align-text-bottom" vertical_align="text_bottom" viewBox="0 0 14 16" version="1.1" width="14" aria-hidden="true"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74L14 6z"></path></svg>

        Star
</button>        <a class="social-count js-social-count" href="/microresearch/allcolours/stargazers"
           aria-label="0 users starred this repository">
          0
        </a>
</form>  </div>

  </li>

  <li>
        <span class="btn btn-sm btn-with-count disabled tooltipped tooltipped-sw" aria-label="Cannot fork because you own this repository and are not a member of any organizations.">
          <svg class="octicon octicon-repo-forked v-align-text-bottom" viewBox="0 0 10 16" version="1.1" width="10" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 1a1.993 1.993 0 00-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 002 1a1.993 1.993 0 00-1 3.72V6.5l3 3v1.78A1.993 1.993 0 005 15a1.993 1.993 0 001-3.72V9.5l3-3V4.72A1.993 1.993 0 008 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"></path></svg>
          Fork
</span>
    <a href="/microresearch/allcolours/network/members" class="social-count"
       aria-label="0 users forked this repository">
      0
    </a>
  </li>
</ul>

    </div>
      
<nav class="hx_reponav reponav js-repo-nav js-sidenav-container-pjax clearfix container-lg p-responsive d-none d-lg-block"
     itemscope
     itemtype="http://schema.org/BreadcrumbList"
    aria-label="Repository"
     data-pjax="#js-repo-pjax-container">

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a class="js-selected-navigation-item selected reponav-item" itemprop="url" data-hotkey="g c" aria-current="page" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches repo_packages /microresearch/allcolours" href="/microresearch/allcolours">
      <div class="d-inline"><svg class="octicon octicon-code" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M9.5 3L8 4.5 11.5 8 8 11.5 9.5 13 14 8 9.5 3zm-5 0L0 8l4.5 5L6 11.5 2.5 8 6 4.5 4.5 3z"></path></svg></div>
      <span itemprop="name">Code</span>
      <meta itemprop="position" content="1">
</a>  </span>

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a itemprop="url" data-hotkey="g i" class="js-selected-navigation-item reponav-item" data-selected-links="repo_issues repo_labels repo_milestones /microresearch/allcolours/issues" href="/microresearch/allcolours/issues">
        <div class="d-inline"><svg class="octicon octicon-issue-opened" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7 2.3c3.14 0 5.7 2.56 5.7 5.7s-2.56 5.7-5.7 5.7A5.71 5.71 0 011.3 8c0-3.14 2.56-5.7 5.7-5.7zM7 1C3.14 1 0 4.14 0 8s3.14 7 7 7 7-3.14 7-7-3.14-7-7-7zm1 3H6v5h2V4zm0 6H6v2h2v-2z"></path></svg></div>
        <span itemprop="name">Issues</span>
        <span class="Counter">0</span>
        <meta itemprop="position" content="2">
</a>    </span>

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a data-hotkey="g p" data-skip-pjax="true" itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_pulls checks /microresearch/allcolours/pulls" href="/microresearch/allcolours/pulls">
      <div class="d-inline"><svg class="octicon octicon-git-pull-request" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M11 11.28V5c-.03-.78-.34-1.47-.94-2.06C9.46 2.35 8.78 2.03 8 2H7V0L4 3l3 3V4h1c.27.02.48.11.69.31.21.2.3.42.31.69v6.28A1.993 1.993 0 0010 15a1.993 1.993 0 001-3.72zm-1 2.92c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zM4 3c0-1.11-.89-2-2-2a1.993 1.993 0 00-1 3.72v6.56A1.993 1.993 0 002 15a1.993 1.993 0 001-3.72V4.72c.59-.34 1-.98 1-1.72zm-.8 10c0 .66-.55 1.2-1.2 1.2-.65 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"></path></svg></div>
      <span itemprop="name">Pull requests</span>
      <span class="Counter">0</span>
      <meta itemprop="position" content="4">
</a>  </span>


    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement" class="position-relative float-left">
      <a data-hotkey="g w" data-skip-pjax="true" class="js-selected-navigation-item reponav-item" data-selected-links="repo_actions /microresearch/allcolours/actions" href="/microresearch/allcolours/actions">
        <div class="d-inline"><svg class="octicon octicon-play" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 8A7 7 0 110 8a7 7 0 0114 0zm-8.223 3.482l4.599-3.066a.5.5 0 000-.832L5.777 4.518A.5.5 0 005 4.934v6.132a.5.5 0 00.777.416z"></path></svg></div>
        Actions
</a>
    </span>

    <a data-hotkey="g b" class="js-selected-navigation-item reponav-item" data-selected-links="repo_projects new_repo_project repo_project /microresearch/allcolours/projects" href="/microresearch/allcolours/projects">
      <div class="d-inline"><svg class="octicon octicon-project" viewBox="0 0 15 16" version="1.1" width="15" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 00-1 1v14a1 1 0 001 1h13a1 1 0 001-1V1a1 1 0 00-1-1z"></path></svg></div>
      Projects
      <span class="Counter">0</span>
</a>
    <a class="js-selected-navigation-item reponav-item" data-hotkey="g w" data-selected-links="repo_wiki /microresearch/allcolours/wiki" href="/microresearch/allcolours/wiki">
      <div class="d-inline"><svg class="octicon octicon-book" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M3 5h4v1H3V5zm0 3h4V7H3v1zm0 2h4V9H3v1zm11-5h-4v1h4V5zm0 2h-4v1h4V7zm0 2h-4v1h4V9zm2-6v9c0 .55-.45 1-1 1H9.5l-1 1-1-1H2c-.55 0-1-.45-1-1V3c0-.55.45-1 1-1h5.5l1 1 1-1H15c.55 0 1 .45 1 1zm-8 .5L7.5 3H2v9h6V3.5zm7-.5H9.5l-.5.5V12h6V3z"></path></svg></div>
      Wiki
</a>
    <a data-skip-pjax="true" class="js-selected-navigation-item reponav-item" data-selected-links="security overview alerts policy token_scanning code_scanning /microresearch/allcolours/security" href="/microresearch/allcolours/security">
      <div class="d-inline"><svg class="octicon octicon-shield" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M0 2l7-2 7 2v6.02C14 12.69 8.69 16 7 16c-1.69 0-7-3.31-7-7.98V2zm1 .75L7 1l6 1.75v5.268C13 12.104 8.449 15 7 15c-1.449 0-6-2.896-6-6.982V2.75zm1 .75L7 2v12c-1.207 0-5-2.482-5-5.985V3.5z"></path></svg></div>
      Security
</a>
    <a class="js-selected-navigation-item reponav-item" data-selected-links="repo_graphs repo_contributors dependency_graph dependabot_updates pulse people /microresearch/allcolours/pulse" href="/microresearch/allcolours/pulse">
      <div class="d-inline"><svg class="octicon octicon-graph" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M16 14v1H0V0h1v14h15zM5 13H3V8h2v5zm4 0H7V3h2v10zm4 0h-2V6h2v7z"></path></svg></div>
      Insights
</a>
    <a class="js-selected-navigation-item reponav-item" data-selected-links="repo_settings repo_branch_settings hooks integration_installations repo_keys_settings issue_template_editor secrets_settings key_links_settings repo_actions_settings notifications /microresearch/allcolours/settings" href="/microresearch/allcolours/settings">
      <div class="d-inline"><svg class="octicon octicon-gear" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 8.77v-1.6l-1.94-.64-.45-1.09.88-1.84-1.13-1.13-1.81.91-1.09-.45-.69-1.92h-1.6l-.63 1.94-1.11.45-1.84-.88-1.13 1.13.91 1.81-.45 1.09L0 7.23v1.59l1.94.64.45 1.09-.88 1.84 1.13 1.13 1.81-.91 1.09.45.69 1.92h1.59l.63-1.94 1.11-.45 1.84.88 1.13-1.13-.92-1.81.47-1.09L14 8.75v.02zM7 11c-1.66 0-3-1.34-3-3s1.34-3 3-3 3 1.34 3 3-1.34 3-3 3z"></path></svg></div>
      Settings
</a>
</nav>

  <div class="reponav-wrapper reponav-small d-lg-none">
  <nav class="reponav js-reponav text-center no-wrap"
       itemscope
       itemtype="http://schema.org/BreadcrumbList">

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a class="js-selected-navigation-item selected reponav-item" itemprop="url" aria-current="page" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches repo_packages /microresearch/allcolours" href="/microresearch/allcolours">
        <span itemprop="name">Code</span>
        <meta itemprop="position" content="1">
</a>    </span>

      <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
        <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_issues repo_labels repo_milestones /microresearch/allcolours/issues" href="/microresearch/allcolours/issues">
          <span itemprop="name">Issues</span>
          <span class="Counter">0</span>
          <meta itemprop="position" content="2">
</a>      </span>

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_pulls checks /microresearch/allcolours/pulls" href="/microresearch/allcolours/pulls">
        <span itemprop="name">Pull requests</span>
        <span class="Counter">0</span>
        <meta itemprop="position" content="4">
</a>    </span>


      <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
        <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_projects new_repo_project repo_project /microresearch/allcolours/projects" href="/microresearch/allcolours/projects">
          <span itemprop="name">Projects</span>
          <span class="Counter">0</span>
          <meta itemprop="position" content="5">
</a>      </span>

      <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
        <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_actions /microresearch/allcolours/actions" href="/microresearch/allcolours/actions">
          <span itemprop="name">Actions</span>
          <meta itemprop="position" content="6">
</a>      </span>

      <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
        <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_wiki /microresearch/allcolours/wiki" href="/microresearch/allcolours/wiki">
          <span itemprop="name">Wiki</span>
          <meta itemprop="position" content="7">
</a>      </span>

      <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="security overview alerts policy token_scanning code_scanning /microresearch/allcolours/security" href="/microresearch/allcolours/security">
        <span itemprop="name">Security</span>
        <meta itemprop="position" content="8">
</a>
      <a class="js-selected-navigation-item reponav-item" data-selected-links="pulse /microresearch/allcolours/pulse" href="/microresearch/allcolours/pulse">
        Pulse
</a>
      <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
        <a itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="community /microresearch/allcolours/community" href="/microresearch/allcolours/community">
          Community
</a>      </span>

  </nav>
</div>


  </div>

  

  <include-fragment class="js-notification-shelf-include-fragment" data-base-src="https://github.com/notifications/beta/shelf"></include-fragment>


<div class="container-lg clearfix new-discussion-timeline  p-responsive">
  <div class="repository-content ">

    
    

  


    <a class="d-none js-permalink-shortcut" data-hotkey="y" href="/microresearch/allcolours/blob/cbbae983cfc43bc6e5ab6ab247f026e9ba4ef81c/software/STM32F103/src/stm32f10x_it.c">Permalink</a>

    <!-- blob contrib key: blob_contributors:v22:8eae47a3c705c7056337c126ce34006e -->
    

    <div class="d-flex flex-items-start flex-shrink-0 flex-column flex-md-row pb-3">
      <span class="d-flex flex-justify-between width-full width-md-auto">
        
<details class="details-reset details-overlay branch-select-menu " id="branch-select-menu">
  <summary class="btn css-truncate btn-sm"
           data-hotkey="w"
           title="Switch branches or tags">
    <i>Branch:</i>
    <span class="css-truncate-target" data-menu-button>master</span>
    <span class="dropdown-caret"></span>
  </summary>

  <details-menu class="SelectMenu SelectMenu--hasFilter" src="/microresearch/allcolours/refs/master/software/STM32F103/src/stm32f10x_it.c?source_action=show&amp;source_controller=blob" preload>
    <div class="SelectMenu-modal">
      <include-fragment class="SelectMenu-loading" aria-label="Menu is loading">
        <svg class="octicon octicon-octoface anim-pulse" height="32" viewBox="0 0 16 16" version="1.1" width="32" aria-hidden="true"><path fill-rule="evenodd" d="M14.7 5.34c.13-.32.55-1.59-.13-3.31 0 0-1.05-.33-3.44 1.3-1-.28-2.07-.32-3.13-.32s-2.13.04-3.13.32c-2.39-1.64-3.44-1.3-3.44-1.3-.68 1.72-.26 2.99-.13 3.31C.49 6.21 0 7.33 0 8.69 0 13.84 3.33 15 7.98 15S16 13.84 16 8.69c0-1.36-.49-2.48-1.3-3.35zM8 14.02c-3.3 0-5.98-.15-5.98-3.35 0-.76.38-1.48 1.02-2.07 1.07-.98 2.9-.46 4.96-.46 2.07 0 3.88-.52 4.96.46.65.59 1.02 1.3 1.02 2.07 0 3.19-2.68 3.35-5.98 3.35zM5.49 9.01c-.66 0-1.2.8-1.2 1.78s.54 1.79 1.2 1.79c.66 0 1.2-.8 1.2-1.79s-.54-1.78-1.2-1.78zm5.02 0c-.66 0-1.2.79-1.2 1.78s.54 1.79 1.2 1.79c.66 0 1.2-.8 1.2-1.79s-.53-1.78-1.2-1.78z"></path></svg>
      </include-fragment>
    </div>
  </details-menu>
</details>

        <div class="BtnGroup flex-shrink-0 d-md-none">
          <a href="/microresearch/allcolours/find/master"
                class="js-pjax-capture-input btn btn-sm BtnGroup-item"
                data-pjax
                data-hotkey="t">
            Find file
          </a>
          <clipboard-copy value="software/STM32F103/src/stm32f10x_it.c" class="btn btn-sm BtnGroup-item">
            Copy path
          </clipboard-copy>
        </div>
      </span>
      <h2 id="blob-path" class="breadcrumb flex-auto min-width-0 text-normal flex-md-self-center ml-md-2 mr-md-3 my-2 my-md-0">
        <span class="js-repo-root text-bold"><span class="js-path-segment"><a data-pjax="true" href="/microresearch/allcolours"><span>allcolours</span></a></span></span><span class="separator">/</span><span class="js-path-segment"><a data-pjax="true" href="/microresearch/allcolours/tree/master/software"><span>software</span></a></span><span class="separator">/</span><span class="js-path-segment"><a data-pjax="true" href="/microresearch/allcolours/tree/master/software/STM32F103"><span>STM32F103</span></a></span><span class="separator">/</span><span class="js-path-segment"><a data-pjax="true" href="/microresearch/allcolours/tree/master/software/STM32F103/src"><span>src</span></a></span><span class="separator">/</span><strong class="final-path">stm32f10x_it.c</strong>
      </h2>

      <div class="BtnGroup flex-shrink-0 d-none d-md-inline-block">
        <a href="/microresearch/allcolours/find/master"
              class="js-pjax-capture-input btn btn-sm BtnGroup-item"
              data-pjax
              data-hotkey="t">
          Find file
        </a>
        <clipboard-copy value="software/STM32F103/src/stm32f10x_it.c" class="btn btn-sm BtnGroup-item">
          Copy path
        </clipboard-copy>
      </div>
    </div>



    <include-fragment src="/microresearch/allcolours/contributors/master/software/STM32F103/src/stm32f10x_it.c" class="Box Box--condensed commit-loader">
      <div class="Box-body bg-blue-light f6">
        Fetching contributors&hellip;
      </div>

      <div class="Box-body d-flex flex-items-center" >
        <img alt="" class="loader-loading mr-2" src="https://github.githubassets.com/images/spinners/octocat-spinner-32-EAF2F5.gif" width="16" height="16" />
        <span class="text-red h6 loader-error">Cannot retrieve contributors at this time</span>
      </div>
</include-fragment>





    <div class="Box mt-3 position-relative
      ">
      
<div class="Box-header py-2 d-flex flex-column flex-shrink-0 flex-md-row flex-md-items-center">
  <div class="text-mono f6 flex-auto pr-3 flex-order-2 flex-md-order-1 mt-2 mt-md-0">

      1586 lines (1325 sloc)
      <span class="file-info-divider"></span>
    82.9 KB
  </div>

  <div class="d-flex py-1 py-md-0 flex-auto flex-order-1 flex-md-order-2 flex-sm-grow-0 flex-justify-between">

    <div class="BtnGroup">
      <a id="raw-url" class="btn btn-sm BtnGroup-item" href="/microresearch/allcolours/raw/master/software/STM32F103/src/stm32f10x_it.c">Raw</a>
        <a class="btn btn-sm js-update-url-with-hash BtnGroup-item" data-hotkey="b" href="/microresearch/allcolours/blame/master/software/STM32F103/src/stm32f10x_it.c">Blame</a>
      <a rel="nofollow" class="btn btn-sm BtnGroup-item" href="/microresearch/allcolours/commits/master/software/STM32F103/src/stm32f10x_it.c">History</a>
    </div>


    <div>
          <a class="btn-octicon tooltipped tooltipped-nw js-remove-unless-platform"
             data-platforms="windows,mac"
             href="https://desktop.github.com"
             aria-label="Open this file in GitHub Desktop"
             data-ga-click="Repository, open with desktop">
              <svg class="octicon octicon-device-desktop" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M15 2H1c-.55 0-1 .45-1 1v9c0 .55.45 1 1 1h5.34c-.25.61-.86 1.39-2.34 2h8c-1.48-.61-2.09-1.39-2.34-2H15c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm0 9H1V3h14v8z"></path></svg>
          </a>

          <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="inline-form js-update-url-with-hash" action="/microresearch/allcolours/edit/master/software/STM32F103/src/stm32f10x_it.c" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="SG27oC4J8ivcW/rsUaeKKMzw36sLNARp2qBJW8S9iXRQinfcKrwte3llvwGm9Buwz3abipUVJ6yS5zZV6E+Khw==" />
            <button class="btn-octicon tooltipped tooltipped-nw" type="submit"
              aria-label="Edit this file" data-hotkey="e" data-disable-with>
              <svg class="octicon octicon-pencil" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M0 12v3h3l8-8-3-3-8 8zm3 2H1v-2h1v1h1v1zm10.3-9.3L12 6 9 3l1.3-1.3a.996.996 0 011.41 0l1.59 1.59c.39.39.39 1.02 0 1.41z"></path></svg>
            </button>
</form>
          <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="inline-form" action="/microresearch/allcolours/delete/master/software/STM32F103/src/stm32f10x_it.c" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="DE2sLvHriCkcEHPcfqnMgd9dxBN4D9ka8DjXyRafHnxTa0iZMJ0i003/+mmKruAn40UL3RypZRpvdiugMUrQUg==" />
            <button class="btn-octicon btn-octicon-danger tooltipped tooltipped-nw" type="submit"
              aria-label="Delete this file" data-disable-with>
              <svg class="octicon octicon-trashcan" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M11 2H9c0-.55-.45-1-1-1H5c-.55 0-1 .45-1 1H2c-.55 0-1 .45-1 1v1c0 .55.45 1 1 1v9c0 .55.45 1 1 1h7c.55 0 1-.45 1-1V5c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm-1 12H3V5h1v8h1V5h1v8h1V5h1v8h1V5h1v9zm1-10H2V3h9v1z"></path></svg>
            </button>
</form>    </div>
  </div>
</div>



      

  <div itemprop="text" class="Box-body p-0 blob-wrapper data type-c ">
      
<table class="highlight tab-size js-file-line-container" data-tab-size="8" data-paste-markdown-skip>
      <tr>
        <td id="L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&quot;</span>stm32f10x_it.h<span class="pl-pds">&quot;</span></span></td>
      </tr>
      <tr>
        <td id="L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">/*</span> SR/PWM modes in interrupts...</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-code blob-code-inner js-file-line"><span class="pl-c">List of Shift Register modes = CV and pulse driven:</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-code blob-code-inner js-file-line"><span class="pl-c">List of PWM modes now:</span></td>
      </tr>
      <tr>
        <td id="L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-code blob-code-inner js-file-line"><span class="pl-c">0-CV </span></td>
      </tr>
      <tr>
        <td id="L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-code blob-code-inner js-file-line"><span class="pl-c">1-CV - SR CV/speed inverted</span></td>
      </tr>
      <tr>
        <td id="L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-code blob-code-inner js-file-line"><span class="pl-c">TODO: </span></td>
      </tr>
      <tr>
        <td id="L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-code blob-code-inner js-file-line"><span class="pl-c">- selected low and high, CV and pulse modes</span></td>
      </tr>
      <tr>
        <td id="L15" class="blob-num js-line-number" data-line-number="15"></td>
        <td id="LC15" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L16" class="blob-num js-line-number" data-line-number="16"></td>
        <td id="LC16" class="blob-code blob-code-inner js-file-line"><span class="pl-c">*CV_HF: 0, 1, 2, 3, 4, 7, 9, 23, 25, 26, 28, 29, 34, 35, 36, 41*</span></td>
      </tr>
      <tr>
        <td id="L17" class="blob-num js-line-number" data-line-number="17"></td>
        <td id="LC17" class="blob-code blob-code-inner js-file-line"><span class="pl-c">*CV_LF: 0, 1, 2, 3, 4, 7, 9, 23, 30, 32, 33, 34, 35, 37, 39, 40*</span></td>
      </tr>
      <tr>
        <td id="L18" class="blob-num js-line-number" data-line-number="18"></td>
        <td id="LC18" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L19" class="blob-num js-line-number" data-line-number="19"></td>
        <td id="LC19" class="blob-code blob-code-inner js-file-line"><span class="pl-c">*PULSE_HF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 48, 50, 52, 53, 56, 57, 58*</span></td>
      </tr>
      <tr>
        <td id="L20" class="blob-num js-line-number" data-line-number="20"></td>
        <td id="LC20" class="blob-code blob-code-inner js-file-line"><span class="pl-c">*PULSE_LF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 47, 51, 52, 53, 56, 57, 58*</span></td>
      </tr>
      <tr>
        <td id="L21" class="blob-num js-line-number" data-line-number="21"></td>
        <td id="LC21" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L22" class="blob-num js-line-number" data-line-number="22"></td>
        <td id="LC22" class="blob-code blob-code-inner js-file-line"><span class="pl-c">- function pointer/array speed test with main.c -&gt; test below</span></td>
      </tr>
      <tr>
        <td id="L23" class="blob-num js-line-number" data-line-number="23"></td>
        <td id="LC23" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L24" class="blob-num js-line-number" data-line-number="24"></td>
        <td id="LC24" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L25" class="blob-num js-line-number" data-line-number="25"></td>
        <td id="LC25" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L26" class="blob-num js-line-number" data-line-number="26"></td>
        <td id="LC26" class="blob-code blob-code-inner js-file-line"><span class="pl-k">extern</span> __IO <span class="pl-c1">uint16_t</span> ADCBuffer[];</td>
      </tr>
      <tr>
        <td id="L27" class="blob-num js-line-number" data-line-number="27"></td>
        <td id="LC27" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> speedh, speedl, counterh=<span class="pl-c1">0</span>, counter12h=<span class="pl-c1">0</span>, counter12l=<span class="pl-c1">0</span>,speedhh, speedll, counterl=<span class="pl-c1">0</span>; <span class="pl-c"><span class="pl-c">//</span> hfpulsecount, lfpulsecount;</span></td>
      </tr>
      <tr>
        <td id="L28" class="blob-num js-line-number" data-line-number="28"></td>
        <td id="LC28" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> modelpwm, modehpwm, modelsr=<span class="pl-c1">0</span>, modehsr=<span class="pl-c1">0</span>, hcount=<span class="pl-c1">0</span>, lcount=<span class="pl-c1">0</span>; <span class="pl-c"><span class="pl-c">//</span> testing for modes</span></td>
      </tr>
      <tr>
        <td id="L29" class="blob-num js-line-number" data-line-number="29"></td>
        <td id="LC29" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint8_t</span> new_state[<span class="pl-c1">32</span>], prev_state[<span class="pl-c1">32</span>]={<span class="pl-c1">0</span>}, flipped[<span class="pl-c1">32</span>]={<span class="pl-c1">0</span>}, new_statel[<span class="pl-c1">32</span>], prev_statel[<span class="pl-c1">32</span>]={<span class="pl-c1">0</span>}, flippedl[<span class="pl-c1">32</span>]={<span class="pl-c1">0</span>}, probh, probl, togglel;</td>
      </tr>
      <tr>
        <td id="L30" class="blob-num js-line-number" data-line-number="30"></td>
        <td id="LC30" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> shift_registerh=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> 32 bit SR but we can change length just using output bit</span></td>
      </tr>
      <tr>
        <td id="L31" class="blob-num js-line-number" data-line-number="31"></td>
        <td id="LC31" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> shift_registerl=<span class="pl-c1">0xff</span>; </td>
      </tr>
      <tr>
        <td id="L32" class="blob-num js-line-number" data-line-number="32"></td>
        <td id="LC32" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> shift_registerx=<span class="pl-c1">0xff</span>;</td>
      </tr>
      <tr>
        <td id="L33" class="blob-num js-line-number" data-line-number="33"></td>
        <td id="LC33" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> shift_registerxl=<span class="pl-c1">0xff</span>;</td>
      </tr>
      <tr>
        <td id="L34" class="blob-num js-line-number" data-line-number="34"></td>
        <td id="LC34" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> SRlengthh=<span class="pl-c1">31</span>, SRlengthl=<span class="pl-c1">31</span>, hstack[<span class="pl-c1">4</span>], lstack[<span class="pl-c1">4</span>]; <span class="pl-c"><span class="pl-c">//</span> length minus 1;</span></td>
      </tr>
      <tr>
        <td id="L35" class="blob-num js-line-number" data-line-number="35"></td>
        <td id="LC35" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> model, modeh, lengthbith=(<span class="pl-c1">1</span>&lt;&lt;<span class="pl-c1">15</span>), lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;<span class="pl-c1">15</span>);</td>
      </tr>
      <tr>
        <td id="L36" class="blob-num js-line-number" data-line-number="36"></td>
        <td id="LC36" class="blob-code blob-code-inner js-file-line"><span class="pl-k">volatile</span> <span class="pl-c1">uint32_t</span> bith=<span class="pl-c1">0</span>, bitl=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L37" class="blob-num js-line-number" data-line-number="37"></td>
        <td id="LC37" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span>volatile uint32_t lastspeedhh, lastspeedll;</span></td>
      </tr>
      <tr>
        <td id="L38" class="blob-num js-line-number" data-line-number="38"></td>
        <td id="LC38" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L39" class="blob-num js-line-number" data-line-number="39"></td>
        <td id="LC39" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">delay</span>(<span class="pl-k">unsigned</span> <span class="pl-k">long</span> delay)</td>
      </tr>
      <tr>
        <td id="L40" class="blob-num js-line-number" data-line-number="40"></td>
        <td id="LC40" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L41" class="blob-num js-line-number" data-line-number="41"></td>
        <td id="LC41" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">while</span>(delay) {</td>
      </tr>
      <tr>
        <td id="L42" class="blob-num js-line-number" data-line-number="42"></td>
        <td id="LC42" class="blob-code blob-code-inner js-file-line">    delay--;</td>
      </tr>
      <tr>
        <td id="L43" class="blob-num js-line-number" data-line-number="43"></td>
        <td id="LC43" class="blob-code blob-code-inner js-file-line"> <span class="pl-c1">asm</span>(<span class="pl-s"><span class="pl-pds">&quot;</span><span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L44" class="blob-num js-line-number" data-line-number="44"></td>
        <td id="LC44" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L45" class="blob-num js-line-number" data-line-number="45"></td>
        <td id="LC45" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L46" class="blob-num js-line-number" data-line-number="46"></td>
        <td id="LC46" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L47" class="blob-num js-line-number" data-line-number="47"></td>
        <td id="LC47" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">NMI_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L48" class="blob-num js-line-number" data-line-number="48"></td>
        <td id="LC48" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L49" class="blob-num js-line-number" data-line-number="49"></td>
        <td id="LC49" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L50" class="blob-num js-line-number" data-line-number="50"></td>
        <td id="LC50" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L51" class="blob-num js-line-number" data-line-number="51"></td>
        <td id="LC51" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">HardFault_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L52" class="blob-num js-line-number" data-line-number="52"></td>
        <td id="LC52" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L53" class="blob-num js-line-number" data-line-number="53"></td>
        <td id="LC53" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">/*</span> Go to infinite loop when Hard Fault exception occurs <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L54" class="blob-num js-line-number" data-line-number="54"></td>
        <td id="LC54" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">while</span> (<span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L55" class="blob-num js-line-number" data-line-number="55"></td>
        <td id="LC55" class="blob-code blob-code-inner js-file-line">  {</td>
      </tr>
      <tr>
        <td id="L56" class="blob-num js-line-number" data-line-number="56"></td>
        <td id="LC56" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L57" class="blob-num js-line-number" data-line-number="57"></td>
        <td id="LC57" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L58" class="blob-num js-line-number" data-line-number="58"></td>
        <td id="LC58" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L59" class="blob-num js-line-number" data-line-number="59"></td>
        <td id="LC59" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">MemManage_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L60" class="blob-num js-line-number" data-line-number="60"></td>
        <td id="LC60" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L61" class="blob-num js-line-number" data-line-number="61"></td>
        <td id="LC61" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">/*</span> Go to infinite loop when Memory Manage exception occurs <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L62" class="blob-num js-line-number" data-line-number="62"></td>
        <td id="LC62" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">while</span> (<span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L63" class="blob-num js-line-number" data-line-number="63"></td>
        <td id="LC63" class="blob-code blob-code-inner js-file-line">  {</td>
      </tr>
      <tr>
        <td id="L64" class="blob-num js-line-number" data-line-number="64"></td>
        <td id="LC64" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L65" class="blob-num js-line-number" data-line-number="65"></td>
        <td id="LC65" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L66" class="blob-num js-line-number" data-line-number="66"></td>
        <td id="LC66" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L67" class="blob-num js-line-number" data-line-number="67"></td>
        <td id="LC67" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">BusFault_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L68" class="blob-num js-line-number" data-line-number="68"></td>
        <td id="LC68" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L69" class="blob-num js-line-number" data-line-number="69"></td>
        <td id="LC69" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">/*</span> Go to infinite loop when Bus Fault exception occurs <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L70" class="blob-num js-line-number" data-line-number="70"></td>
        <td id="LC70" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">while</span> (<span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L71" class="blob-num js-line-number" data-line-number="71"></td>
        <td id="LC71" class="blob-code blob-code-inner js-file-line">  {</td>
      </tr>
      <tr>
        <td id="L72" class="blob-num js-line-number" data-line-number="72"></td>
        <td id="LC72" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L73" class="blob-num js-line-number" data-line-number="73"></td>
        <td id="LC73" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L74" class="blob-num js-line-number" data-line-number="74"></td>
        <td id="LC74" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">UsageFault_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L75" class="blob-num js-line-number" data-line-number="75"></td>
        <td id="LC75" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L76" class="blob-num js-line-number" data-line-number="76"></td>
        <td id="LC76" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">/*</span> Go to infinite loop when Usage Fault exception occurs <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L77" class="blob-num js-line-number" data-line-number="77"></td>
        <td id="LC77" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">while</span> (<span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L78" class="blob-num js-line-number" data-line-number="78"></td>
        <td id="LC78" class="blob-code blob-code-inner js-file-line">  {</td>
      </tr>
      <tr>
        <td id="L79" class="blob-num js-line-number" data-line-number="79"></td>
        <td id="LC79" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L80" class="blob-num js-line-number" data-line-number="80"></td>
        <td id="LC80" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L81" class="blob-num js-line-number" data-line-number="81"></td>
        <td id="LC81" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">SVC_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L82" class="blob-num js-line-number" data-line-number="82"></td>
        <td id="LC82" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L83" class="blob-num js-line-number" data-line-number="83"></td>
        <td id="LC83" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L84" class="blob-num js-line-number" data-line-number="84"></td>
        <td id="LC84" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L85" class="blob-num js-line-number" data-line-number="85"></td>
        <td id="LC85" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">DebugMon_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L86" class="blob-num js-line-number" data-line-number="86"></td>
        <td id="LC86" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L87" class="blob-num js-line-number" data-line-number="87"></td>
        <td id="LC87" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L88" class="blob-num js-line-number" data-line-number="88"></td>
        <td id="LC88" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L89" class="blob-num js-line-number" data-line-number="89"></td>
        <td id="LC89" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">PendSV_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L90" class="blob-num js-line-number" data-line-number="90"></td>
        <td id="LC90" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L91" class="blob-num js-line-number" data-line-number="91"></td>
        <td id="LC91" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L92" class="blob-num js-line-number" data-line-number="92"></td>
        <td id="LC92" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L93" class="blob-num js-line-number" data-line-number="93"></td>
        <td id="LC93" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">SysTick_Handler</span>(<span class="pl-k">void</span>)</td>
      </tr>
      <tr>
        <td id="L94" class="blob-num js-line-number" data-line-number="94"></td>
        <td id="LC94" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L95" class="blob-num js-line-number" data-line-number="95"></td>
        <td id="LC95" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L96" class="blob-num js-line-number" data-line-number="96"></td>
        <td id="LC96" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L97" class="blob-num js-line-number" data-line-number="97"></td>
        <td id="LC97" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> for mode 13-electronotes = probh is not linear as we are interested in the number of bits set and not their position</span></td>
      </tr>
      <tr>
        <td id="L98" class="blob-num js-line-number" data-line-number="98"></td>
        <td id="LC98" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> there are 8 positions which is 3 bits or we can make 16?</span></td>
      </tr>
      <tr>
        <td id="L99" class="blob-num js-line-number" data-line-number="99"></td>
        <td id="LC99" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint32_t</span> electroprob[<span class="pl-c1">8</span>]={<span class="pl-c1">0</span>, <span class="pl-c1">3</span>, <span class="pl-c1">7</span>, <span class="pl-c1">15</span>, <span class="pl-c1">31</span>, <span class="pl-c1">63</span>, <span class="pl-c1">127</span>, <span class="pl-c1">255</span>};</td>
      </tr>
      <tr>
        <td id="L100" class="blob-num js-line-number" data-line-number="100"></td>
        <td id="LC100" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L101" class="blob-num js-line-number" data-line-number="101"></td>
        <td id="LC101" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint32_t</span> MASK[<span class="pl-c1">32</span>]={<span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294967040</span>, <span class="pl-c1">4294966785</span>, <span class="pl-c1">4294966275</span>, <span class="pl-c1">4294965255</span>, <span class="pl-c1">4294963215</span>, <span class="pl-c1">4294959135</span>, <span class="pl-c1">4294950975</span>, <span class="pl-c1">4294934655</span>, <span class="pl-c1">4294902015</span>, <span class="pl-c1">4294836735</span>, <span class="pl-c1">4294706175</span>, <span class="pl-c1">4294445055</span>, <span class="pl-c1">4293922815</span>, <span class="pl-c1">4292878335</span>, <span class="pl-c1">4290789375</span>, <span class="pl-c1">4286611455</span>, <span class="pl-c1">4278255615</span>, <span class="pl-c1">4261543935</span>, <span class="pl-c1">4228120575</span>, <span class="pl-c1">4161273855</span>, <span class="pl-c1">4027580415</span>, <span class="pl-c1">3760193535</span>, <span class="pl-c1">3225419775</span>, <span class="pl-c1">2155872255</span>, <span class="pl-c1">16777215</span>};</td>
      </tr>
      <tr>
        <td id="L102" class="blob-num js-line-number" data-line-number="102"></td>
        <td id="LC102" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L103" class="blob-num js-line-number" data-line-number="103"></td>
        <td id="LC103" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint32_t</span> SHIFT[<span class="pl-c1">32</span>]={<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">1</span>, <span class="pl-c1">2</span>, <span class="pl-c1">3</span>, <span class="pl-c1">4</span>, <span class="pl-c1">5</span>, <span class="pl-c1">6</span>, <span class="pl-c1">7</span>, <span class="pl-c1">8</span>, <span class="pl-c1">9</span>, <span class="pl-c1">10</span>, <span class="pl-c1">11</span>, <span class="pl-c1">12</span>, <span class="pl-c1">13</span>, <span class="pl-c1">14</span>, <span class="pl-c1">15</span>, <span class="pl-c1">16</span>, <span class="pl-c1">17</span>, <span class="pl-c1">18</span>, <span class="pl-c1">19</span>, <span class="pl-c1">20</span>, <span class="pl-c1">21</span>, <span class="pl-c1">22</span>, <span class="pl-c1">23</span>, <span class="pl-c1">24</span>}; </td>
      </tr>
      <tr>
        <td id="L104" class="blob-num js-line-number" data-line-number="104"></td>
        <td id="LC104" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L105" class="blob-num js-line-number" data-line-number="105"></td>
        <td id="LC105" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> log_gen:     print(&quot;%s,&quot; % int(1+(((starter*xyz)-312)/32))),</span></td>
      </tr>
      <tr>
        <td id="L106" class="blob-num js-line-number" data-line-number="106"></td>
        <td id="LC106" class="blob-code blob-code-inner js-file-line">			 </td>
      </tr>
      <tr>
        <td id="L107" class="blob-num js-line-number" data-line-number="107"></td>
        <td id="LC107" class="blob-code blob-code-inner js-file-line">static uint16_t logger[1024]={312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 326, 327, 328, 329, 330, 331, 332, 333, 334, 336, 337, 338, 339, 340, 341, 343, 344, 345, 346, 347, 348, 350, 351, 352, 353, 354, 356, 357, 358, 359, 360, 362, 363, 364, 365, 367, 368, 369, 370, 372, 373, 374, 375, 377, 378, 379, 380, 382, 383, 384, 386, 387, 388, 390, 391, 392, 394, 395, 396, 398, 399, 400, 402, 403, 404, 406, 407, 409, 410, 411, 413, 414, 416, 417, 418, 420, 421, 423, 424, 425, 427, 428, 430, 431, 433, 434, 436, 437, 439, 440, 442, 443, 445, 446, 448, 449, 451, 452, 454, 455, 457, 458, 460, 462, 463, 465, 466, 468, 469, 471, 473, 474, 476, 477, 479, 481, 482, 484, 486, 487, 489, 491, 492, 494, 496, 497, 499, 501, 502, 504, 506, 507, 509, 511, 513, 514, 516, 518, 520, 521, 523, 525, 527, 528, 530, 532, 534, 536, 538, 539, 541, 543, 545, 547, 549, 550, 552, 554, 556, 558, 560, 562, 564, 566, 567, 569, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 601, 603, 605, 607, 609, 611, 613, 616, 618, 620, 622, 624, 626, 628, 630, 632, 635, 637, 639, 641, 643, 645, 648, 650, 652, 654, 656, 659, 661, 663, 665, 668, 670, 672, 674, 677, 679, 681, 684, 686, 688, 691, 693, 695, 698, 700, 702, 705, 707, 710, 712, 714, 717, 719, 722, 724, 727, 729, 732, 734, 737, 739, 742, 744, 747, 749, 752, 754, 757, 759, 762, 765, 767, 770, 772, 775, 778, 780, 783, 786, 788, 791, 794, 796, 799, 802, 804, 807, 810, 813, 815, 818, 821, 824, 826, 829, 832, 835, 838, 841, 843, 846, 849, 852, 855, 858, 861, 864, 867, 870, 872, 875, 878, 881, 884, 887, 890, 893, 896, 899, 903, 906, 909, 912, 915, 918, 921, 924, 927, 930, 934, 937, 940, 943, 946, 950, 953, 956, 959, 962, 966, 969, 972, 976, 979, 982, 986, 989, 992, 996, 999, 1002, 1006, 1009, 1013, 1016, 1020, 1023, 1026, 1030, 1033, 1037, 1040, 1044, 1048, 1051, 1055, 1058, 1062, 1065, 1069, 1073, 1076, 1080, 1084, 1087, 1091, 1095, 1098, 1102, 1106, 1110, 1113, 1117, 1121, 1125, 1129, 1132, 1136, 1140, 1144, 1148, 1152, 1156, 1160, 1163, 1167, 1171, 1175, 1179, 1183, 1187, 1191, 1195, 1199, 1204, 1208, 1212, 1216, 1220, 1224, 1228, 1232, 1237, 1241, 1245, 1249, 1253, 1258, 1262, 1266, 1271, 1275, 1279, 1283, 1288, 1292, 1297, 1301, 1305, 1310, 1314, 1319, 1323, 1328, 1332, 1337, 1341, 1346, 1350, 1355, 1360, 1364, 1369, 1373, 1378, 1383, 1387, 1392, 1397, 1402, 1406, 1411, 1416, 1421, 1426, 1430, 1435, 1440, 1445, 1450, 1455, 1460, 1465, 1470, 1475, 1480, 1485, 1490, 1495, 1500, 1505, 1510, 1515, 1520, 1525, 1531, 1536, 1541, 1546, 1551, 1557, 1562, 1567, 1573, 1578, 1583, 1589, 1594, 1599, 1605, 1610, 1616, 1621, 1627, 1632, 1638, 1643, 1649, 1655, 1660, 1666, 1671, 1677, 1683, 1688, 1694, 1700, 1706, 1711, 1717, 1723, 1729, 1735, 1741, 1747, 1753, 1758, 1764, 1770, 1776, 1782, 1788, 1795, 1801, 1807, 1813, 1819, 1825, 1831, 1838, 1844, 1850, 1856, 1863, 1869, 1875, 1882, 1888, 1894, 1901, 1907, 1914, 1920, 1927, 1933, 1940, 1946, 1953, 1960, 1966, 1973, 1980, 1986, 1993, 2000, 2007, 2013, 2020, 2027, 2034, 2041, 2048, 2055, 2062, 2069, 2076, 2083, 2090, 2097, 2104, 2111, 2118, 2126, 2133, 2140, 2147, 2155, 2162, 2169, 2177, 2184, 2191, 2199, 2206, 2214, 2221, 2229, 2236, 2244, 2251, 2259, 2267, 2274, 2282, 2290, 2298, 2305, 2313, 2321, 2329, 2337, 2345, 2353, 2361, 2369, 2377, 2385, 2393, 2401, 2409, 2417, 2426, 2434, 2442, 2450, 2459, 2467, 2475, 2484, 2492, 2501, 2509, 2518, 2526, 2535, 2543, 2552, 2561, 2569, 2578, 2587, 2595, 2604, 2613, 2622, 2631, 2640, 2649, 2658, 2667, 2676, 2685, 2694, 2703, 2712, 2721, 2731, 2740, 2749, 2759, 2768, 2777, 2787, 2796, 2806, 2815, 2825, 2834, 2844, 2853, 2863, 2873, 2883, 2892, 2902, 2912, 2922, 2932, 2942, 2952, 2962, 2972, 2982, 2992, 3002, 3012, 3023, 3033, 3043, 3053, 3064, 3074, 3085, 3095, 3105, 3116, 3127, 3137, 3148, 3158, 3169, 3180, 3191, 3202, 3212, 3223, 3234, 3245, 3256, 3267, 3278, 3289, 3301, 3312, 3323, 3334, 3346, 3357, 3368, 3380, 3391, 3403, 3414, 3426, 3437, 3449, 3461, 3472, 3484, 3496, 3508, 3520, 3532, 3544, 3556, 3568, 3580, 3592, 3604, 3616, 3629, 3641, 3653, 3666, 3678, 3691, 3703, 3716, 3728, 3741, 3754, 3766, 3779, 3792, 3805, 3818, 3831, 3844, 3857, 3870, 3883, 3896, 3909, 3923, 3936, 3949, 3963, 3976, 3989, 4003, 4017, 4030, 4044, 4058, 4071, 4085, 4099, 4113, 4127, 4141, 4155, 4169, 4183, 4197, 4211, 4226, 4240, 4254, 4269, 4283, 4298, 4312, 4327, 4342, 4356, 4371, 4386, 4401, 4416, 4431, 4446, 4461, 4476, 4491, 4506, 4522, 4537, 4552, 4568, 4583, 4599, 4615, 4630, 4646, 4662, 4677, 4693, 4709, 4725, 4741, 4757, 4773, 4790, 4806, 4822, 4838, 4855, 4871, 4888, 4904, 4921, 4938, 4954, 4971, 4988, 5005, 5022, 5039, 5056, 5073, 5090, 5108, 5125, 5142, 5160, 5177, 5195, 5213, 5230, 5248, 5266, 5284, 5301, 5319, 5337, 5356, 5374, 5392, 5410, 5429, 5447, 5465, 5484, 5503, 5521, 5540, 5559, 5578, 5597, 5615, 5635, 5654, 5673, 5692, 5711, 5731, 5750, 5770, 5789, 5809, 5829, 5848, 5868, 5888, 5908, 5928, 5948, 5968, 5988, 6009, 6029, 6050, 6070, 6091, 6111, 6132, 6153, 6174, 6195, 6216, 6237, 6258, 6279, 6300, 6322, 6343, 6365, 6386, 6408, 6430, 6451, 6473, 6495, 6517, 6539, 6562, 6584, 6606, 6629, 6651, 6674, 6696, 6719, 6742, 6765, 6787, 6810, 6834, 6857, 6880, 6903, 6927, 6950, 6974, 6997, 7021, 7045, 7069, 7093, 7117, 7141, 7165, 7189, 7214, 7238, 7263, 7287, 7312, 7337, 7362, 7387, 7412, 7437, 7462, 7487, 7513, 7538, 7564, 7590, 7615, 7641, 7667, 7693, 7719, 7745, 7772, 7798, 7824, 7851, 7877, 7904, 7931, 7958, 7985, 8012, 8039, 8066, 8094, 8121, 8149, 8176, 8204, 8232, 8260, 8288, 8316, 8344, 8372, 8401, 8429, 8458, 8486, 8515, 8544, 8573, 8602, 8631, 8661, 8690, 8719, 8749, 8779, 8808, 8838, 8868, 8898, 8928, 8959, 8989, 9020, 9050, 9081, 9112, 9142, 9173, 9205, 9236, 9267, 9299, 9330, 9362, 9393, 9425, 9457, 9489, 9521, 9554, 9586, 9619, 9651, 9684, 9717, 9750, 9783, 9816, 9849, 9883, 9916, 9950};</td>
      </tr>
      <tr>
        <td id="L108" class="blob-num js-line-number" data-line-number="108"></td>
        <td id="LC108" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L109" class="blob-num js-line-number" data-line-number="109"></td>
        <td id="LC109" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> logforSR could be a lot slower at one end - test/generate this! 2^14</span></td>
      </tr>
      <tr>
        <td id="L110" class="blob-num js-line-number" data-line-number="110"></td>
        <td id="LC110" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L111" class="blob-num js-line-number" data-line-number="111"></td>
        <td id="LC111" class="blob-code blob-code-inner js-file-line">static uint16_t logforSR[1024]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 42, 42, 43, 43, 43, 44, 44, 45, 45, 46, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 58, 58, 59, 59, 60, 60, 61, 62, 62, 63, 63, 64, 65, 65, 66, 67, 67, 68, 69, 69, 70, 71, 71, 72, 73, 73, 74, 75, 76, 76, 77, 78, 79, 79, 80, 81, 82, 82, 83, 84, 85, 86, 87, 87, 88, 89, 90, 91, 92, 93, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 117, 118, 119, 120, 121, 122, 124, 125, 126, 127, 128, 130, 131, 132, 133, 135, 136, 137, 139, 140, 141, 143, 144, 145, 147, 148, 150, 151, 153, 154, 155, 157, 158, 160, 162, 163, 165, 166, 168, 169, 171, 173, 174, 176, 178, 179, 181, 183, 185, 186, 188, 190, 192, 194, 196, 197, 199, 201, 203, 205, 207, 209, 211, 213, 215, 217, 219, 221, 224, 226, 228, 230, 232, 235, 237, 239, 241, 244, 246, 248, 251, 253, 256, 258, 260, 263, 265, 268, 271, 273, 276, 278, 281, 284, 287, 289, 292, 295, 298, 301, 303, 306, 309, 312, 315, 318, 321, 324, 327, 331, 334, 337, 340, 343, 347, 350, 353, 357, 360, 364, 367, 371, 374, 378, 381, 385, 389, 392, 396, 400, 404, 408, 412, 415, 419, 423, 428, 432, 436, 440, 444, 448, 453, 457, 461, 466, 470, 475, 479, 484, 488, 493, 498, 503, 507, 512, 517, 522, 527, 532, 537, 542, 548, 553, 558, 563, 569, 574, 580, 585, 591, 596, 602, 608, 614, 620, 625, 631, 637, 644, 650, 656, 662, 669, 675, 681, 688, 694, 701, 708, 715, 721, 728, 735, 742, 749, 756, 764, 771, 778, 786, 793, 801, 809, 816, 824, 832, 840, 848, 856, 864, 872, 881, 889, 898, 906, 915, 924, 932, 941, 950, 959, 968, 978, 987, 996, 1006, 1016, 1025, 1035, 1045, 1055, 1065, 1075, 1085, 1096, 1106, 1117, 1127, 1138, 1149, 1160, 1171, 1182, 1194, 1205, 1216, 1228, 1240, 1252, 1264, 1276, 1288, 1300, 1312, 1325, 1338, 1350, 1363, 1376, 1389, 1403, 1416, 1430, 1443, 1457, 1471, 1485, 1499, 1513, 1528, 1542, 1557, 1572, 1587, 1602, 1617, 1633, 1648, 1664, 1680, 1696, 1712, 1729, 1745, 1762, 1778, 1795, 1813, 1830, 1847, 1865, 1883, 1901, 1919, 1937, 1956, 1974, 1993, 2012, 2031, 2051, 2070, 2090, 2110, 2130, 2150, 2171, 2192, 2212, 2234, 2255, 2276, 2298, 2320, 2342, 2364, 2387, 2410, 2433, 2456, 2479, 2503, 2527, 2551, 2575, 2600, 2625, 2650, 2675, 2700, 2726, 2752, 2778, 2805, 2832, 2859, 2886, 2914, 2941, 2969, 2998, 3026, 3055, 3084, 3114, 3143, 3173, 3204, 3234, 3265, 3296, 3328, 3359, 3391, 3424, 3456, 3489, 3522, 3556, 3590, 3624, 3659, 3694, 3729, 3764, 3800, 3837, 3873, 3910, 3947, 3985, 4023, 4061, 4100, 4139, 4179, 4218, 4259, 4299, 4340, 4382, 4423, 4466, 4508, 4551, 4595, 4638, 4683, 4727, 4772, 4818, 4864, 4910, 4957, 5004, 5052, 5100, 5149, 5198, 5247, 5297, 5348, 5399, 5450, 5502, 5555, 5608, 5661, 5715, 5770, 5825, 5880, 5936, 5993, 6050, 6108, 6166, 6225, 6284, 6344, 6404, 6465, 6527, 6589, 6652, 6715, 6779, 6844, 6909, 6975, 7042, 7109, 7177, 7245, 7314, 7384, 7454, 7525, 7597, 7669, 7743, 7816, 7891, 7966, 8042, 8119, 8196, 8274, 8353, 8433, 8513, 8594, 8676, 8759, 8842, 8927, 9012, 9098, 9184, 9272, 9360, 9450, 9540, 9631, 9722, 9815, 9909, 10003, 10098, 10195, 10292, 10390, 10489, 10589, 10690, 10792, 10895, 10999, 11103, 11209, 11316, 11424, 11533, 11643, 11754, 11866, 11979, 12093, 12208, 12325, 12442, 12561, 12681, 12801, 12923, 13047, 13171, 13297, 13423, 13551, 13680, 13811, 13942, 14075, 14210, 14345, 14482, 14620, 14759, 14900, 15042, 15185, 15330, 15476, 15624, 15772, 15923, 16075, 16228, 16383};</td>
      </tr>
      <tr>
        <td id="L112" class="blob-num js-line-number" data-line-number="112"></td>
        <td id="LC112" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L113" class="blob-num js-line-number" data-line-number="113"></td>
        <td id="LC113" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L114" class="blob-num js-line-number" data-line-number="114"></td>
        <td id="LC114" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> array for taps</span></td>
      </tr>
      <tr>
        <td id="L115" class="blob-num js-line-number" data-line-number="115"></td>
        <td id="LC115" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> eg. 32-bit Galois LFSR with taps at 32, 30, 26, 25. Sequence length is 4294967295. 0 is a lock-up state.  -- minus one here - 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L116" class="blob-num js-line-number" data-line-number="116"></td>
        <td id="LC116" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> bith= ((shift_registerh &gt;&gt; 31) ^ (shift_registerh &gt;&gt; 29) ^ (shift_registerh &gt;&gt; 25) ^ (shift_registerh &gt;&gt; 24)) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L117" class="blob-num js-line-number" data-line-number="117"></td>
        <td id="LC117" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L118" class="blob-num js-line-number" data-line-number="118"></td>
        <td id="LC118" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> from: http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf</span></td>
      </tr>
      <tr>
        <td id="L119" class="blob-num js-line-number" data-line-number="119"></td>
        <td id="LC119" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> and reworked for length in test.c -&gt; not so if we revert to basic code...</span></td>
      </tr>
      <tr>
        <td id="L120" class="blob-num js-line-number" data-line-number="120"></td>
        <td id="LC120" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L121" class="blob-num js-line-number" data-line-number="121"></td>
        <td id="LC121" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> note that we can have 2 mirrored with [n, A, B, C] -&gt; [n, n-C, n-B, n-A] - maybe for LF to hF!</span></td>
      </tr>
      <tr>
        <td id="L122" class="blob-num js-line-number" data-line-number="122"></td>
        <td id="LC122" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L123" class="blob-num js-line-number" data-line-number="123"></td>
        <td id="LC123" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint8_t</span> lfsr_taps[<span class="pl-c1">32</span>][<span class="pl-c1">4</span>] = {</td>
      </tr>
      <tr>
        <td id="L124" class="blob-num js-line-number" data-line-number="124"></td>
        <td id="LC124" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L125" class="blob-num js-line-number" data-line-number="125"></td>
        <td id="LC125" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L126" class="blob-num js-line-number" data-line-number="126"></td>
        <td id="LC126" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L127" class="blob-num js-line-number" data-line-number="127"></td>
        <td id="LC127" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L128" class="blob-num js-line-number" data-line-number="128"></td>
        <td id="LC128" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">4</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L129" class="blob-num js-line-number" data-line-number="129"></td>
        <td id="LC129" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L130" class="blob-num js-line-number" data-line-number="130"></td>
        <td id="LC130" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">6</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>},</td>
      </tr>
      <tr>
        <td id="L131" class="blob-num js-line-number" data-line-number="131"></td>
        <td id="LC131" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">7</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>},</td>
      </tr>
      <tr>
        <td id="L132" class="blob-num js-line-number" data-line-number="132"></td>
        <td id="LC132" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">8</span>, <span class="pl-c1">7</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>},</td>
      </tr>
      <tr>
        <td id="L133" class="blob-num js-line-number" data-line-number="133"></td>
        <td id="LC133" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">9</span>, <span class="pl-c1">8</span>, <span class="pl-c1">6</span>, <span class="pl-c1">5</span>},</td>
      </tr>
      <tr>
        <td id="L134" class="blob-num js-line-number" data-line-number="134"></td>
        <td id="LC134" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">10</span>, <span class="pl-c1">9</span>, <span class="pl-c1">8</span>, <span class="pl-c1">6</span>},</td>
      </tr>
      <tr>
        <td id="L135" class="blob-num js-line-number" data-line-number="135"></td>
        <td id="LC135" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">11</span>, <span class="pl-c1">10</span>, <span class="pl-c1">7</span>, <span class="pl-c1">5</span>},</td>
      </tr>
      <tr>
        <td id="L136" class="blob-num js-line-number" data-line-number="136"></td>
        <td id="LC136" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">12</span>, <span class="pl-c1">11</span>, <span class="pl-c1">9</span>, <span class="pl-c1">8</span>},</td>
      </tr>
      <tr>
        <td id="L137" class="blob-num js-line-number" data-line-number="137"></td>
        <td id="LC137" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>, <span class="pl-c1">8</span>},</td>
      </tr>
      <tr>
        <td id="L138" class="blob-num js-line-number" data-line-number="138"></td>
        <td id="LC138" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">14</span>, <span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>},</td>
      </tr>
      <tr>
        <td id="L139" class="blob-num js-line-number" data-line-number="139"></td>
        <td id="LC139" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">15</span>, <span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>},</td>
      </tr>
      <tr>
        <td id="L140" class="blob-num js-line-number" data-line-number="140"></td>
        <td id="LC140" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">16</span>, <span class="pl-c1">15</span>, <span class="pl-c1">14</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L141" class="blob-num js-line-number" data-line-number="141"></td>
        <td id="LC141" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">17</span>, <span class="pl-c1">16</span>, <span class="pl-c1">15</span>, <span class="pl-c1">12</span>},</td>
      </tr>
      <tr>
        <td id="L142" class="blob-num js-line-number" data-line-number="142"></td>
        <td id="LC142" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">18</span>, <span class="pl-c1">17</span>, <span class="pl-c1">16</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L143" class="blob-num js-line-number" data-line-number="143"></td>
        <td id="LC143" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">19</span>, <span class="pl-c1">18</span>, <span class="pl-c1">15</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L144" class="blob-num js-line-number" data-line-number="144"></td>
        <td id="LC144" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">20</span>, <span class="pl-c1">19</span>, <span class="pl-c1">18</span>, <span class="pl-c1">15</span>},</td>
      </tr>
      <tr>
        <td id="L145" class="blob-num js-line-number" data-line-number="145"></td>
        <td id="LC145" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">21</span>, <span class="pl-c1">18</span>, <span class="pl-c1">17</span>, <span class="pl-c1">16</span>},</td>
      </tr>
      <tr>
        <td id="L146" class="blob-num js-line-number" data-line-number="146"></td>
        <td id="LC146" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">22</span>, <span class="pl-c1">21</span>, <span class="pl-c1">19</span>, <span class="pl-c1">17</span>},</td>
      </tr>
      <tr>
        <td id="L147" class="blob-num js-line-number" data-line-number="147"></td>
        <td id="LC147" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">23</span>, <span class="pl-c1">22</span>, <span class="pl-c1">20</span>, <span class="pl-c1">19</span>},</td>
      </tr>
      <tr>
        <td id="L148" class="blob-num js-line-number" data-line-number="148"></td>
        <td id="LC148" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">24</span>, <span class="pl-c1">23</span>, <span class="pl-c1">22</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L149" class="blob-num js-line-number" data-line-number="149"></td>
        <td id="LC149" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">25</span>, <span class="pl-c1">24</span>, <span class="pl-c1">23</span>, <span class="pl-c1">19</span>},</td>
      </tr>
      <tr>
        <td id="L150" class="blob-num js-line-number" data-line-number="150"></td>
        <td id="LC150" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">26</span>, <span class="pl-c1">25</span>, <span class="pl-c1">24</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L151" class="blob-num js-line-number" data-line-number="151"></td>
        <td id="LC151" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">27</span>, <span class="pl-c1">26</span>, <span class="pl-c1">23</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L152" class="blob-num js-line-number" data-line-number="152"></td>
        <td id="LC152" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">28</span>, <span class="pl-c1">27</span>, <span class="pl-c1">26</span>, <span class="pl-c1">24</span>},</td>
      </tr>
      <tr>
        <td id="L153" class="blob-num js-line-number" data-line-number="153"></td>
        <td id="LC153" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">29</span>, <span class="pl-c1">28</span>, <span class="pl-c1">25</span>, <span class="pl-c1">23</span>},</td>
      </tr>
      <tr>
        <td id="L154" class="blob-num js-line-number" data-line-number="154"></td>
        <td id="LC154" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">30</span>, <span class="pl-c1">29</span>, <span class="pl-c1">28</span>, <span class="pl-c1">27</span>},</td>
      </tr>
      <tr>
        <td id="L155" class="blob-num js-line-number" data-line-number="155"></td>
        <td id="LC155" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">31</span>, <span class="pl-c1">29</span>, <span class="pl-c1">25</span>, <span class="pl-c1">24</span>},</td>
      </tr>
      <tr>
        <td id="L156" class="blob-num js-line-number" data-line-number="156"></td>
        <td id="LC156" class="blob-code blob-code-inner js-file-line">  };</td>
      </tr>
      <tr>
        <td id="L157" class="blob-num js-line-number" data-line-number="157"></td>
        <td id="LC157" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L158" class="blob-num js-line-number" data-line-number="158"></td>
        <td id="LC158" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint8_t</span> ghost_tapsH[<span class="pl-c1">32</span>][<span class="pl-c1">4</span>] = {</td>
      </tr>
      <tr>
        <td id="L159" class="blob-num js-line-number" data-line-number="159"></td>
        <td id="LC159" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L160" class="blob-num js-line-number" data-line-number="160"></td>
        <td id="LC160" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L161" class="blob-num js-line-number" data-line-number="161"></td>
        <td id="LC161" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L162" class="blob-num js-line-number" data-line-number="162"></td>
        <td id="LC162" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L163" class="blob-num js-line-number" data-line-number="163"></td>
        <td id="LC163" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">4</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L164" class="blob-num js-line-number" data-line-number="164"></td>
        <td id="LC164" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L165" class="blob-num js-line-number" data-line-number="165"></td>
        <td id="LC165" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">6</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>},</td>
      </tr>
      <tr>
        <td id="L166" class="blob-num js-line-number" data-line-number="166"></td>
        <td id="LC166" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">7</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>},</td>
      </tr>
      <tr>
        <td id="L167" class="blob-num js-line-number" data-line-number="167"></td>
        <td id="LC167" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">8</span>, <span class="pl-c1">7</span>, <span class="pl-c1">5</span>, <span class="pl-c1">4</span>},</td>
      </tr>
      <tr>
        <td id="L168" class="blob-num js-line-number" data-line-number="168"></td>
        <td id="LC168" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">9</span>, <span class="pl-c1">8</span>, <span class="pl-c1">6</span>, <span class="pl-c1">5</span>},</td>
      </tr>
      <tr>
        <td id="L169" class="blob-num js-line-number" data-line-number="169"></td>
        <td id="LC169" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">10</span>, <span class="pl-c1">9</span>, <span class="pl-c1">8</span>, <span class="pl-c1">6</span>},</td>
      </tr>
      <tr>
        <td id="L170" class="blob-num js-line-number" data-line-number="170"></td>
        <td id="LC170" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">11</span>, <span class="pl-c1">10</span>, <span class="pl-c1">7</span>, <span class="pl-c1">5</span>},</td>
      </tr>
      <tr>
        <td id="L171" class="blob-num js-line-number" data-line-number="171"></td>
        <td id="LC171" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">12</span>, <span class="pl-c1">11</span>, <span class="pl-c1">9</span>, <span class="pl-c1">8</span>},</td>
      </tr>
      <tr>
        <td id="L172" class="blob-num js-line-number" data-line-number="172"></td>
        <td id="LC172" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>, <span class="pl-c1">8</span>},</td>
      </tr>
      <tr>
        <td id="L173" class="blob-num js-line-number" data-line-number="173"></td>
        <td id="LC173" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">14</span>, <span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>},</td>
      </tr>
      <tr>
        <td id="L174" class="blob-num js-line-number" data-line-number="174"></td>
        <td id="LC174" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">15</span>, <span class="pl-c1">13</span>, <span class="pl-c1">12</span>, <span class="pl-c1">10</span>},</td>
      </tr>
      <tr>
        <td id="L175" class="blob-num js-line-number" data-line-number="175"></td>
        <td id="LC175" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">16</span>, <span class="pl-c1">15</span>, <span class="pl-c1">14</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L176" class="blob-num js-line-number" data-line-number="176"></td>
        <td id="LC176" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">17</span>, <span class="pl-c1">16</span>, <span class="pl-c1">15</span>, <span class="pl-c1">12</span>},</td>
      </tr>
      <tr>
        <td id="L177" class="blob-num js-line-number" data-line-number="177"></td>
        <td id="LC177" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">18</span>, <span class="pl-c1">17</span>, <span class="pl-c1">16</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L178" class="blob-num js-line-number" data-line-number="178"></td>
        <td id="LC178" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">19</span>, <span class="pl-c1">18</span>, <span class="pl-c1">15</span>, <span class="pl-c1">13</span>},</td>
      </tr>
      <tr>
        <td id="L179" class="blob-num js-line-number" data-line-number="179"></td>
        <td id="LC179" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">20</span>, <span class="pl-c1">19</span>, <span class="pl-c1">18</span>, <span class="pl-c1">15</span>},</td>
      </tr>
      <tr>
        <td id="L180" class="blob-num js-line-number" data-line-number="180"></td>
        <td id="LC180" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">21</span>, <span class="pl-c1">18</span>, <span class="pl-c1">17</span>, <span class="pl-c1">16</span>},</td>
      </tr>
      <tr>
        <td id="L181" class="blob-num js-line-number" data-line-number="181"></td>
        <td id="LC181" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">22</span>, <span class="pl-c1">21</span>, <span class="pl-c1">19</span>, <span class="pl-c1">17</span>},</td>
      </tr>
      <tr>
        <td id="L182" class="blob-num js-line-number" data-line-number="182"></td>
        <td id="LC182" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">23</span>, <span class="pl-c1">22</span>, <span class="pl-c1">20</span>, <span class="pl-c1">19</span>},</td>
      </tr>
      <tr>
        <td id="L183" class="blob-num js-line-number" data-line-number="183"></td>
        <td id="LC183" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">24</span>, <span class="pl-c1">23</span>, <span class="pl-c1">22</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L184" class="blob-num js-line-number" data-line-number="184"></td>
        <td id="LC184" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">25</span>, <span class="pl-c1">24</span>, <span class="pl-c1">23</span>, <span class="pl-c1">19</span>},</td>
      </tr>
      <tr>
        <td id="L185" class="blob-num js-line-number" data-line-number="185"></td>
        <td id="LC185" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">26</span>, <span class="pl-c1">25</span>, <span class="pl-c1">24</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L186" class="blob-num js-line-number" data-line-number="186"></td>
        <td id="LC186" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">27</span>, <span class="pl-c1">26</span>, <span class="pl-c1">23</span>, <span class="pl-c1">21</span>},</td>
      </tr>
      <tr>
        <td id="L187" class="blob-num js-line-number" data-line-number="187"></td>
        <td id="LC187" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">28</span>, <span class="pl-c1">27</span>, <span class="pl-c1">26</span>, <span class="pl-c1">24</span>},</td>
      </tr>
      <tr>
        <td id="L188" class="blob-num js-line-number" data-line-number="188"></td>
        <td id="LC188" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">29</span>, <span class="pl-c1">28</span>, <span class="pl-c1">25</span>, <span class="pl-c1">23</span>},</td>
      </tr>
      <tr>
        <td id="L189" class="blob-num js-line-number" data-line-number="189"></td>
        <td id="LC189" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">30</span>, <span class="pl-c1">29</span>, <span class="pl-c1">28</span>, <span class="pl-c1">27</span>},</td>
      </tr>
      <tr>
        <td id="L190" class="blob-num js-line-number" data-line-number="190"></td>
        <td id="LC190" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">31</span>, <span class="pl-c1">29</span>, <span class="pl-c1">25</span>, <span class="pl-c1">24</span>},</td>
      </tr>
      <tr>
        <td id="L191" class="blob-num js-line-number" data-line-number="191"></td>
        <td id="LC191" class="blob-code blob-code-inner js-file-line">  };</td>
      </tr>
      <tr>
        <td id="L192" class="blob-num js-line-number" data-line-number="192"></td>
        <td id="LC192" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L193" class="blob-num js-line-number" data-line-number="193"></td>
        <td id="LC193" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L194" class="blob-num js-line-number" data-line-number="194"></td>
        <td id="LC194" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint8_t</span> lfsr_taps_mirrored[<span class="pl-c1">32</span>][<span class="pl-c1">4</span>] = {</td>
      </tr>
      <tr>
        <td id="L195" class="blob-num js-line-number" data-line-number="195"></td>
        <td id="LC195" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L196" class="blob-num js-line-number" data-line-number="196"></td>
        <td id="LC196" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L197" class="blob-num js-line-number" data-line-number="197"></td>
        <td id="LC197" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L198" class="blob-num js-line-number" data-line-number="198"></td>
        <td id="LC198" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L199" class="blob-num js-line-number" data-line-number="199"></td>
        <td id="LC199" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L200" class="blob-num js-line-number" data-line-number="200"></td>
        <td id="LC200" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L201" class="blob-num js-line-number" data-line-number="201"></td>
        <td id="LC201" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">6</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L202" class="blob-num js-line-number" data-line-number="202"></td>
        <td id="LC202" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">7</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L203" class="blob-num js-line-number" data-line-number="203"></td>
        <td id="LC203" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">8</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L204" class="blob-num js-line-number" data-line-number="204"></td>
        <td id="LC204" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">9</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L205" class="blob-num js-line-number" data-line-number="205"></td>
        <td id="LC205" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">10</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L206" class="blob-num js-line-number" data-line-number="206"></td>
        <td id="LC206" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">11</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L207" class="blob-num js-line-number" data-line-number="207"></td>
        <td id="LC207" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">12</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L208" class="blob-num js-line-number" data-line-number="208"></td>
        <td id="LC208" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">13</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L209" class="blob-num js-line-number" data-line-number="209"></td>
        <td id="LC209" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">14</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L210" class="blob-num js-line-number" data-line-number="210"></td>
        <td id="LC210" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">15</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L211" class="blob-num js-line-number" data-line-number="211"></td>
        <td id="LC211" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">16</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L212" class="blob-num js-line-number" data-line-number="212"></td>
        <td id="LC212" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">17</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L213" class="blob-num js-line-number" data-line-number="213"></td>
        <td id="LC213" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">18</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L214" class="blob-num js-line-number" data-line-number="214"></td>
        <td id="LC214" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">19</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L215" class="blob-num js-line-number" data-line-number="215"></td>
        <td id="LC215" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">20</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L216" class="blob-num js-line-number" data-line-number="216"></td>
        <td id="LC216" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">21</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>},</td>
      </tr>
      <tr>
        <td id="L217" class="blob-num js-line-number" data-line-number="217"></td>
        <td id="LC217" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">22</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L218" class="blob-num js-line-number" data-line-number="218"></td>
        <td id="LC218" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">23</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L219" class="blob-num js-line-number" data-line-number="219"></td>
        <td id="LC219" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">24</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L220" class="blob-num js-line-number" data-line-number="220"></td>
        <td id="LC220" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">25</span>, <span class="pl-c1">5</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L221" class="blob-num js-line-number" data-line-number="221"></td>
        <td id="LC221" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">26</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L222" class="blob-num js-line-number" data-line-number="222"></td>
        <td id="LC222" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">27</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L223" class="blob-num js-line-number" data-line-number="223"></td>
        <td id="LC223" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">28</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L224" class="blob-num js-line-number" data-line-number="224"></td>
        <td id="LC224" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">29</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L225" class="blob-num js-line-number" data-line-number="225"></td>
        <td id="LC225" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">30</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L226" class="blob-num js-line-number" data-line-number="226"></td>
        <td id="LC226" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">31</span>, <span class="pl-c1">6</span>, <span class="pl-c1">5</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L227" class="blob-num js-line-number" data-line-number="227"></td>
        <td id="LC227" class="blob-code blob-code-inner js-file-line">	 };</td>
      </tr>
      <tr>
        <td id="L228" class="blob-num js-line-number" data-line-number="228"></td>
        <td id="LC228" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L229" class="blob-num js-line-number" data-line-number="229"></td>
        <td id="LC229" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-c1">uint8_t</span> ghost_tapsL[<span class="pl-c1">32</span>][<span class="pl-c1">4</span>] = {</td>
      </tr>
      <tr>
        <td id="L230" class="blob-num js-line-number" data-line-number="230"></td>
        <td id="LC230" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L231" class="blob-num js-line-number" data-line-number="231"></td>
        <td id="LC231" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L232" class="blob-num js-line-number" data-line-number="232"></td>
        <td id="LC232" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">0</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L233" class="blob-num js-line-number" data-line-number="233"></td>
        <td id="LC233" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L234" class="blob-num js-line-number" data-line-number="234"></td>
        <td id="LC234" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L235" class="blob-num js-line-number" data-line-number="235"></td>
        <td id="LC235" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L236" class="blob-num js-line-number" data-line-number="236"></td>
        <td id="LC236" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">6</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L237" class="blob-num js-line-number" data-line-number="237"></td>
        <td id="LC237" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">7</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L238" class="blob-num js-line-number" data-line-number="238"></td>
        <td id="LC238" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">8</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L239" class="blob-num js-line-number" data-line-number="239"></td>
        <td id="LC239" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">9</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L240" class="blob-num js-line-number" data-line-number="240"></td>
        <td id="LC240" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">10</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L241" class="blob-num js-line-number" data-line-number="241"></td>
        <td id="LC241" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">11</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L242" class="blob-num js-line-number" data-line-number="242"></td>
        <td id="LC242" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">12</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L243" class="blob-num js-line-number" data-line-number="243"></td>
        <td id="LC243" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">13</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L244" class="blob-num js-line-number" data-line-number="244"></td>
        <td id="LC244" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">14</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L245" class="blob-num js-line-number" data-line-number="245"></td>
        <td id="LC245" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">15</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L246" class="blob-num js-line-number" data-line-number="246"></td>
        <td id="LC246" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">16</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L247" class="blob-num js-line-number" data-line-number="247"></td>
        <td id="LC247" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">17</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L248" class="blob-num js-line-number" data-line-number="248"></td>
        <td id="LC248" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">18</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L249" class="blob-num js-line-number" data-line-number="249"></td>
        <td id="LC249" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">19</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L250" class="blob-num js-line-number" data-line-number="250"></td>
        <td id="LC250" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">20</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L251" class="blob-num js-line-number" data-line-number="251"></td>
        <td id="LC251" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">21</span>, <span class="pl-c1">4</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>},</td>
      </tr>
      <tr>
        <td id="L252" class="blob-num js-line-number" data-line-number="252"></td>
        <td id="LC252" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">22</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L253" class="blob-num js-line-number" data-line-number="253"></td>
        <td id="LC253" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">23</span>, <span class="pl-c1">3</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L254" class="blob-num js-line-number" data-line-number="254"></td>
        <td id="LC254" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">24</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L255" class="blob-num js-line-number" data-line-number="255"></td>
        <td id="LC255" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">25</span>, <span class="pl-c1">5</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L256" class="blob-num js-line-number" data-line-number="256"></td>
        <td id="LC256" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">26</span>, <span class="pl-c1">4</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L257" class="blob-num js-line-number" data-line-number="257"></td>
        <td id="LC257" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">27</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L258" class="blob-num js-line-number" data-line-number="258"></td>
        <td id="LC258" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">28</span>, <span class="pl-c1">3</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L259" class="blob-num js-line-number" data-line-number="259"></td>
        <td id="LC259" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">29</span>, <span class="pl-c1">5</span>, <span class="pl-c1">3</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L260" class="blob-num js-line-number" data-line-number="260"></td>
        <td id="LC260" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">30</span>, <span class="pl-c1">2</span>, <span class="pl-c1">1</span>, <span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L261" class="blob-num js-line-number" data-line-number="261"></td>
        <td id="LC261" class="blob-code blob-code-inner js-file-line">        {<span class="pl-c1">31</span>, <span class="pl-c1">6</span>, <span class="pl-c1">5</span>, <span class="pl-c1">1</span>},</td>
      </tr>
      <tr>
        <td id="L262" class="blob-num js-line-number" data-line-number="262"></td>
        <td id="LC262" class="blob-code blob-code-inner js-file-line">	 };</td>
      </tr>
      <tr>
        <td id="L263" class="blob-num js-line-number" data-line-number="263"></td>
        <td id="LC263" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L264" class="blob-num js-line-number" data-line-number="264"></td>
        <td id="LC264" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">TIM2_IRQHandler</span>(<span class="pl-k">void</span>){</td>
      </tr>
      <tr>
        <td id="L265" class="blob-num js-line-number" data-line-number="265"></td>
        <td id="LC265" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L266" class="blob-num js-line-number" data-line-number="266"></td>
        <td id="LC266" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> handle LF and HF SR for selected modes and also handle PWM which follows SR (mode 2)</span></td>
      </tr>
      <tr>
        <td id="L267" class="blob-num js-line-number" data-line-number="267"></td>
        <td id="LC267" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint32_t</span> tmp;</td>
      </tr>
      <tr>
        <td id="L268" class="blob-num js-line-number" data-line-number="268"></td>
        <td id="LC268" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint32_t</span> SRlengthx=<span class="pl-c1">31</span>;</td>
      </tr>
      <tr>
        <td id="L269" class="blob-num js-line-number" data-line-number="269"></td>
        <td id="LC269" class="blob-code blob-code-inner js-file-line">  </td>
      </tr>
      <tr>
        <td id="L270" class="blob-num js-line-number" data-line-number="270"></td>
        <td id="LC270" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">TIM_ClearITPendingBit</span>(TIM2, TIM_IT_Update);</td>
      </tr>
      <tr>
        <td id="L271" class="blob-num js-line-number" data-line-number="271"></td>
        <td id="LC271" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L272" class="blob-num js-line-number" data-line-number="272"></td>
        <td id="LC272" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span>//////////////////////////////////////////-&gt;&gt;&gt;    /// low side</span></td>
      </tr>
      <tr>
        <td id="L273" class="blob-num js-line-number" data-line-number="273"></td>
        <td id="LC273" class="blob-code blob-code-inner js-file-line">    counterl++;</td>
      </tr>
      <tr>
        <td id="L274" class="blob-num js-line-number" data-line-number="274"></td>
        <td id="LC274" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span> (counterl&gt;speedll){</td>
      </tr>
      <tr>
        <td id="L275" class="blob-num js-line-number" data-line-number="275"></td>
        <td id="LC275" class="blob-code blob-code-inner js-file-line">    counterl=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L276" class="blob-num js-line-number" data-line-number="276"></td>
        <td id="LC276" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L277" class="blob-num js-line-number" data-line-number="277"></td>
        <td id="LC277" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span>*CV_LF: 0, 1, 2, 3, 4, 7, 9, 23, 30, 32, 33, 34, 35, 37, 39, 40*</span></td>
      </tr>
      <tr>
        <td id="L278" class="blob-num js-line-number" data-line-number="278"></td>
        <td id="LC278" class="blob-code blob-code-inner js-file-line">  </td>
      </tr>
      <tr>
        <td id="L279" class="blob-num js-line-number" data-line-number="279"></td>
        <td id="LC279" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">switch</span>(modelsr){ <span class="pl-c"><span class="pl-c">//</span> use mirrored taps also!</span></td>
      </tr>
      <tr>
        <td id="L280" class="blob-num js-line-number" data-line-number="280"></td>
        <td id="LC280" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">0</span>: </td>
      </tr>
      <tr>
        <td id="L281" class="blob-num js-line-number" data-line-number="281"></td>
        <td id="LC281" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)</span></td>
      </tr>
      <tr>
        <td id="L282" class="blob-num js-line-number" data-line-number="282"></td>
        <td id="LC282" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L283" class="blob-num js-line-number" data-line-number="283"></td>
        <td id="LC283" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L284" class="blob-num js-line-number" data-line-number="284"></td>
        <td id="LC284" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl= (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)); <span class="pl-c"><span class="pl-c">//</span> switched around for speed</span></td>
      </tr>
      <tr>
        <td id="L285" class="blob-num js-line-number" data-line-number="285"></td>
        <td id="LC285" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)); <span class="pl-c"><span class="pl-c">//</span> PB5 and PB6</span></td>
      </tr>
      <tr>
        <td id="L286" class="blob-num js-line-number" data-line-number="286"></td>
        <td id="LC286" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> shift register bits output - inverted on PB13 and 14;</span></td>
      </tr>
      <tr>
        <td id="L287" class="blob-num js-line-number" data-line-number="287"></td>
        <td id="LC287" class="blob-code blob-code-inner js-file-line">      	</td>
      </tr>
      <tr>
        <td id="L288" class="blob-num js-line-number" data-line-number="288"></td>
        <td id="LC288" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PB13 else write one</span></td>
      </tr>
      <tr>
        <td id="L289" class="blob-num js-line-number" data-line-number="289"></td>
        <td id="LC289" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L290" class="blob-num js-line-number" data-line-number="290"></td>
        <td id="LC290" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L291" class="blob-num js-line-number" data-line-number="291"></td>
        <td id="LC291" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L292" class="blob-num js-line-number" data-line-number="292"></td>
        <td id="LC292" class="blob-code blob-code-inner js-file-line">      	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L293" class="blob-num js-line-number" data-line-number="293"></td>
        <td id="LC293" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L294" class="blob-num js-line-number" data-line-number="294"></td>
        <td id="LC294" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">1</span>: </td>
      </tr>
      <tr>
        <td id="L295" class="blob-num js-line-number" data-line-number="295"></td>
        <td id="LC295" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)</span></td>
      </tr>
      <tr>
        <td id="L296" class="blob-num js-line-number" data-line-number="296"></td>
        <td id="LC296" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L297" class="blob-num js-line-number" data-line-number="297"></td>
        <td id="LC297" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L298" class="blob-num js-line-number" data-line-number="298"></td>
        <td id="LC298" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>));</td>
      </tr>
      <tr>
        <td id="L299" class="blob-num js-line-number" data-line-number="299"></td>
        <td id="LC299" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((bitl ^ !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)));</td>
      </tr>
      <tr>
        <td id="L300" class="blob-num js-line-number" data-line-number="300"></td>
        <td id="LC300" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L301" class="blob-num js-line-number" data-line-number="301"></td>
        <td id="LC301" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L302" class="blob-num js-line-number" data-line-number="302"></td>
        <td id="LC302" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L303" class="blob-num js-line-number" data-line-number="303"></td>
        <td id="LC303" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L304" class="blob-num js-line-number" data-line-number="304"></td>
        <td id="LC304" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L305" class="blob-num js-line-number" data-line-number="305"></td>
        <td id="LC305" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L306" class="blob-num js-line-number" data-line-number="306"></td>
        <td id="LC306" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L307" class="blob-num js-line-number" data-line-number="307"></td>
        <td id="LC307" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">2</span>: </td>
      </tr>
      <tr>
        <td id="L308" class="blob-num js-line-number" data-line-number="308"></td>
        <td id="LC308" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse</span></td>
      </tr>
      <tr>
        <td id="L309" class="blob-num js-line-number" data-line-number="309"></td>
        <td id="LC309" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L310" class="blob-num js-line-number" data-line-number="310"></td>
        <td id="LC310" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;SRlengthl) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L311" class="blob-num js-line-number" data-line-number="311"></td>
        <td id="LC311" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L312" class="blob-num js-line-number" data-line-number="312"></td>
        <td id="LC312" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L313" class="blob-num js-line-number" data-line-number="313"></td>
        <td id="LC313" class="blob-code blob-code-inner js-file-line">	shift_registerl= (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>));</td>
      </tr>
      <tr>
        <td id="L314" class="blob-num js-line-number" data-line-number="314"></td>
        <td id="LC314" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L315" class="blob-num js-line-number" data-line-number="315"></td>
        <td id="LC315" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) shift_registerl ^= (<span class="pl-c1">1</span>&lt;&lt;lcount); <span class="pl-c"><span class="pl-c">//</span> if we have pulse and lcount then flip that bit inside SR... rest all the same...</span></td>
      </tr>
      <tr>
        <td id="L316" class="blob-num js-line-number" data-line-number="316"></td>
        <td id="LC316" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L317" class="blob-num js-line-number" data-line-number="317"></td>
        <td id="LC317" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L318" class="blob-num js-line-number" data-line-number="318"></td>
        <td id="LC318" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L319" class="blob-num js-line-number" data-line-number="319"></td>
        <td id="LC319" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L320" class="blob-num js-line-number" data-line-number="320"></td>
        <td id="LC320" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L321" class="blob-num js-line-number" data-line-number="321"></td>
        <td id="LC321" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L322" class="blob-num js-line-number" data-line-number="322"></td>
        <td id="LC322" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L323" class="blob-num js-line-number" data-line-number="323"></td>
        <td id="LC323" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">3</span>: <span class="pl-c"><span class="pl-c">//</span>* </span></td>
      </tr>
      <tr>
        <td id="L324" class="blob-num js-line-number" data-line-number="324"></td>
        <td id="LC324" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)</span></td>
      </tr>
      <tr>
        <td id="L325" class="blob-num js-line-number" data-line-number="325"></td>
        <td id="LC325" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L326" class="blob-num js-line-number" data-line-number="326"></td>
        <td id="LC326" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L327" class="blob-num js-line-number" data-line-number="327"></td>
        <td id="LC327" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L328" class="blob-num js-line-number" data-line-number="328"></td>
        <td id="LC328" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L329" class="blob-num js-line-number" data-line-number="329"></td>
        <td id="LC329" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L330" class="blob-num js-line-number" data-line-number="330"></td>
        <td id="LC330" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L331" class="blob-num js-line-number" data-line-number="331"></td>
        <td id="LC331" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L332" class="blob-num js-line-number" data-line-number="332"></td>
        <td id="LC332" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L333" class="blob-num js-line-number" data-line-number="333"></td>
        <td id="LC333" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L334" class="blob-num js-line-number" data-line-number="334"></td>
        <td id="LC334" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L335" class="blob-num js-line-number" data-line-number="335"></td>
        <td id="LC335" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">4</span>: </td>
      </tr>
      <tr>
        <td id="L336" class="blob-num js-line-number" data-line-number="336"></td>
        <td id="LC336" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 4- parity for loopback XOR is determined by pulsed bits in -&gt; select bits with pulse and queue </span></td>
      </tr>
      <tr>
        <td id="L337" class="blob-num js-line-number" data-line-number="337"></td>
        <td id="LC337" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L338" class="blob-num js-line-number" data-line-number="338"></td>
        <td id="LC338" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;SRlengthl) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L339" class="blob-num js-line-number" data-line-number="339"></td>
        <td id="LC339" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) {</td>
      </tr>
      <tr>
        <td id="L340" class="blob-num js-line-number" data-line-number="340"></td>
        <td id="LC340" class="blob-code blob-code-inner js-file-line">	  lstack[<span class="pl-c1">3</span>]=lstack[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L341" class="blob-num js-line-number" data-line-number="341"></td>
        <td id="LC341" class="blob-code blob-code-inner js-file-line">	  lstack[<span class="pl-c1">2</span>]=lstack[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L342" class="blob-num js-line-number" data-line-number="342"></td>
        <td id="LC342" class="blob-code blob-code-inner js-file-line">	  lstack[<span class="pl-c1">1</span>]=lstack[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L343" class="blob-num js-line-number" data-line-number="343"></td>
        <td id="LC343" class="blob-code blob-code-inner js-file-line">	  lstack[<span class="pl-c1">0</span>]=lcount+<span class="pl-c1">1</span>; <span class="pl-c"><span class="pl-c">//</span> bump it on to the lstack</span></td>
      </tr>
      <tr>
        <td id="L344" class="blob-num js-line-number" data-line-number="344"></td>
        <td id="LC344" class="blob-code blob-code-inner js-file-line">	}	  </td>
      </tr>
      <tr>
        <td id="L345" class="blob-num js-line-number" data-line-number="345"></td>
        <td id="LC345" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L346" class="blob-num js-line-number" data-line-number="346"></td>
        <td id="LC346" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerl &gt;&gt; lstack[<span class="pl-c1">0</span>]) ^ (shift_registerl &gt;&gt; lstack[<span class="pl-c1">1</span>]) ^ (shift_registerl &gt;&gt; lstack[<span class="pl-c1">2</span>]) ^ (shift_registerl &gt;&gt; lstack[<span class="pl-c1">3</span>])) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L347" class="blob-num js-line-number" data-line-number="347"></td>
        <td id="LC347" class="blob-code blob-code-inner js-file-line">	shift_registerl= (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)); <span class="pl-c"><span class="pl-c">//</span> TESTY - to OR in new bit or not?</span></td>
      </tr>
      <tr>
        <td id="L348" class="blob-num js-line-number" data-line-number="348"></td>
        <td id="LC348" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L349" class="blob-num js-line-number" data-line-number="349"></td>
        <td id="LC349" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L350" class="blob-num js-line-number" data-line-number="350"></td>
        <td id="LC350" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L351" class="blob-num js-line-number" data-line-number="351"></td>
        <td id="LC351" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L352" class="blob-num js-line-number" data-line-number="352"></td>
        <td id="LC352" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L353" class="blob-num js-line-number" data-line-number="353"></td>
        <td id="LC353" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L354" class="blob-num js-line-number" data-line-number="354"></td>
        <td id="LC354" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L355" class="blob-num js-line-number" data-line-number="355"></td>
        <td id="LC355" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">5</span>: <span class="pl-c"><span class="pl-c">//</span> was 7</span></td>
      </tr>
      <tr>
        <td id="L356" class="blob-num js-line-number" data-line-number="356"></td>
        <td id="LC356" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?</span></td>
      </tr>
      <tr>
        <td id="L357" class="blob-num js-line-number" data-line-number="357"></td>
        <td id="LC357" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> no use of in bit</span></td>
      </tr>
      <tr>
        <td id="L358" class="blob-num js-line-number" data-line-number="358"></td>
        <td id="LC358" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> !note: swop l and h when port to low!</span></td>
      </tr>
      <tr>
        <td id="L359" class="blob-num js-line-number" data-line-number="359"></td>
        <td id="LC359" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L360" class="blob-num js-line-number" data-line-number="360"></td>
        <td id="LC360" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">7</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L361" class="blob-num js-line-number" data-line-number="361"></td>
        <td id="LC361" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) probl^=(<span class="pl-c1">1</span>&lt;&lt;lcount);</td>
      </tr>
      <tr>
        <td id="L362" class="blob-num js-line-number" data-line-number="362"></td>
        <td id="LC362" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L363" class="blob-num js-line-number" data-line-number="363"></td>
        <td id="LC363" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (((probl | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerh&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> fixed for swop</span></td>
      </tr>
      <tr>
        <td id="L364" class="blob-num js-line-number" data-line-number="364"></td>
        <td id="LC364" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L365" class="blob-num js-line-number" data-line-number="365"></td>
        <td id="LC365" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L366" class="blob-num js-line-number" data-line-number="366"></td>
        <td id="LC366" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L367" class="blob-num js-line-number" data-line-number="367"></td>
        <td id="LC367" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L368" class="blob-num js-line-number" data-line-number="368"></td>
        <td id="LC368" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L369" class="blob-num js-line-number" data-line-number="369"></td>
        <td id="LC369" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L370" class="blob-num js-line-number" data-line-number="370"></td>
        <td id="LC370" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L371" class="blob-num js-line-number" data-line-number="371"></td>
        <td id="LC371" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L372" class="blob-num js-line-number" data-line-number="372"></td>
        <td id="LC372" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">6</span>: <span class="pl-c"><span class="pl-c">//</span> was 9</span></td>
      </tr>
      <tr>
        <td id="L373" class="blob-num js-line-number" data-line-number="373"></td>
        <td id="LC373" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!</span></td>
      </tr>
      <tr>
        <td id="L374" class="blob-num js-line-number" data-line-number="374"></td>
        <td id="LC374" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl==<span class="pl-c1">0</span>) shift_registerl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L375" class="blob-num js-line-number" data-line-number="375"></td>
        <td id="LC375" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">0</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">1</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">2</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L376" class="blob-num js-line-number" data-line-number="376"></td>
        <td id="LC376" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L377" class="blob-num js-line-number" data-line-number="377"></td>
        <td id="LC377" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)); </td>
      </tr>
      <tr>
        <td id="L378" class="blob-num js-line-number" data-line-number="378"></td>
        <td id="LC378" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L379" class="blob-num js-line-number" data-line-number="379"></td>
        <td id="LC379" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L380" class="blob-num js-line-number" data-line-number="380"></td>
        <td id="LC380" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L381" class="blob-num js-line-number" data-line-number="381"></td>
        <td id="LC381" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L382" class="blob-num js-line-number" data-line-number="382"></td>
        <td id="LC382" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L383" class="blob-num js-line-number" data-line-number="383"></td>
        <td id="LC383" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L384" class="blob-num js-line-number" data-line-number="384"></td>
        <td id="LC384" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L385" class="blob-num js-line-number" data-line-number="385"></td>
        <td id="LC385" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">7</span>: <span class="pl-c"><span class="pl-c">//</span>was 23 -  experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L386" class="blob-num js-line-number" data-line-number="386"></td>
        <td id="LC386" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> shifting the array of LFSR taps = ghost_tapsH on the high side</span></td>
      </tr>
      <tr>
        <td id="L387" class="blob-num js-line-number" data-line-number="387"></td>
        <td id="LC387" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> clock pulse shifts one selected by pulse </span></td>
      </tr>
      <tr>
        <td id="L388" class="blob-num js-line-number" data-line-number="388"></td>
        <td id="LC388" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) lcount++;</td>
      </tr>
      <tr>
        <td id="L389" class="blob-num js-line-number" data-line-number="389"></td>
        <td id="LC389" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">3</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L390" class="blob-num js-line-number" data-line-number="390"></td>
        <td id="LC390" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) {</td>
      </tr>
      <tr>
        <td id="L391" class="blob-num js-line-number" data-line-number="391"></td>
        <td id="LC391" class="blob-code blob-code-inner js-file-line">	  ghost_tapsL[SRlengthl][lcount+<span class="pl-c1">1</span>]+=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L392" class="blob-num js-line-number" data-line-number="392"></td>
        <td id="LC392" class="blob-code blob-code-inner js-file-line">	  ghost_tapsL[SRlengthl][lcount+<span class="pl-c1">1</span>]%=SRlengthl;</td>
      </tr>
      <tr>
        <td id="L393" class="blob-num js-line-number" data-line-number="393"></td>
        <td id="LC393" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L394" class="blob-num js-line-number" data-line-number="394"></td>
        <td id="LC394" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L395" class="blob-num js-line-number" data-line-number="395"></td>
        <td id="LC395" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl==<span class="pl-c1">0</span>) shift_registerl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L396" class="blob-num js-line-number" data-line-number="396"></td>
        <td id="LC396" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerl &gt;&gt; (ghost_tapsL[SRlengthl][<span class="pl-c1">0</span>])) ^ (shift_registerl &gt;&gt; (ghost_tapsL[SRlengthl][<span class="pl-c1">1</span>])) ^ (shift_registerl &gt;&gt; (ghost_tapsL[SRlengthl][<span class="pl-c1">2</span>])) ^ (shift_registerl &gt;&gt; (ghost_tapsL[SRlengthl][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L397" class="blob-num js-line-number" data-line-number="397"></td>
        <td id="LC397" class="blob-code blob-code-inner js-file-line">	shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L398" class="blob-num js-line-number" data-line-number="398"></td>
        <td id="LC398" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L399" class="blob-num js-line-number" data-line-number="399"></td>
        <td id="LC399" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L400" class="blob-num js-line-number" data-line-number="400"></td>
        <td id="LC400" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L401" class="blob-num js-line-number" data-line-number="401"></td>
        <td id="LC401" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L402" class="blob-num js-line-number" data-line-number="402"></td>
        <td id="LC402" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L403" class="blob-num js-line-number" data-line-number="403"></td>
        <td id="LC403" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L404" class="blob-num js-line-number" data-line-number="404"></td>
        <td id="LC404" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L405" class="blob-num js-line-number" data-line-number="405"></td>
        <td id="LC405" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">8</span>: <span class="pl-c"><span class="pl-c">//</span> was 30</span></td>
      </tr>
      <tr>
        <td id="L406" class="blob-num js-line-number" data-line-number="406"></td>
        <td id="LC406" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-&gt; our 3 options if we have a bit 0x0020</span></td>
      </tr>
      <tr>
        <td id="L407" class="blob-num js-line-number" data-line-number="407"></td>
        <td id="LC407" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L408" class="blob-num js-line-number" data-line-number="408"></td>
        <td id="LC408" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L409" class="blob-num js-line-number" data-line-number="409"></td>
        <td id="LC409" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L410" class="blob-num js-line-number" data-line-number="410"></td>
        <td id="LC410" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L411" class="blob-num js-line-number" data-line-number="411"></td>
        <td id="LC411" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L412" class="blob-num js-line-number" data-line-number="412"></td>
        <td id="LC412" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)){</td>
      </tr>
      <tr>
        <td id="L413" class="blob-num js-line-number" data-line-number="413"></td>
        <td id="LC413" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L414" class="blob-num js-line-number" data-line-number="414"></td>
        <td id="LC414" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L415" class="blob-num js-line-number" data-line-number="415"></td>
        <td id="LC415" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L416" class="blob-num js-line-number" data-line-number="416"></td>
        <td id="LC416" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L417" class="blob-num js-line-number" data-line-number="417"></td>
        <td id="LC417" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L418" class="blob-num js-line-number" data-line-number="418"></td>
        <td id="LC418" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L419" class="blob-num js-line-number" data-line-number="419"></td>
        <td id="LC419" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L420" class="blob-num js-line-number" data-line-number="420"></td>
        <td id="LC420" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">9</span>: <span class="pl-c"><span class="pl-c">//</span> was 32</span></td>
      </tr>
      <tr>
        <td id="L421" class="blob-num js-line-number" data-line-number="421"></td>
        <td id="LC421" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????</span></td>
      </tr>
      <tr>
        <td id="L422" class="blob-num js-line-number" data-line-number="422"></td>
        <td id="LC422" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-BASE it on::: &gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)</span></td>
      </tr>
      <tr>
        <td id="L423" class="blob-num js-line-number" data-line-number="423"></td>
        <td id="LC423" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L424" class="blob-num js-line-number" data-line-number="424"></td>
        <td id="LC424" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L425" class="blob-num js-line-number" data-line-number="425"></td>
        <td id="LC425" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L426" class="blob-num js-line-number" data-line-number="426"></td>
        <td id="LC426" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L427" class="blob-num js-line-number" data-line-number="427"></td>
        <td id="LC427" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L428" class="blob-num js-line-number" data-line-number="428"></td>
        <td id="LC428" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L429" class="blob-num js-line-number" data-line-number="429"></td>
        <td id="LC429" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L430" class="blob-num js-line-number" data-line-number="430"></td>
        <td id="LC430" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L431" class="blob-num js-line-number" data-line-number="431"></td>
        <td id="LC431" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L432" class="blob-num js-line-number" data-line-number="432"></td>
        <td id="LC432" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L433" class="blob-num js-line-number" data-line-number="433"></td>
        <td id="LC433" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L434" class="blob-num js-line-number" data-line-number="434"></td>
        <td id="LC434" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L435" class="blob-num js-line-number" data-line-number="435"></td>
        <td id="LC435" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">10</span>: <span class="pl-c"><span class="pl-c">//</span> was 33 - and invert the above</span></td>
      </tr>
      <tr>
        <td id="L436" class="blob-num js-line-number" data-line-number="436"></td>
        <td id="LC436" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????</span></td>
      </tr>
      <tr>
        <td id="L437" class="blob-num js-line-number" data-line-number="437"></td>
        <td id="LC437" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-BASE it on::: &gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)</span></td>
      </tr>
      <tr>
        <td id="L438" class="blob-num js-line-number" data-line-number="438"></td>
        <td id="LC438" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L439" class="blob-num js-line-number" data-line-number="439"></td>
        <td id="LC439" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L440" class="blob-num js-line-number" data-line-number="440"></td>
        <td id="LC440" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L441" class="blob-num js-line-number" data-line-number="441"></td>
        <td id="LC441" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L442" class="blob-num js-line-number" data-line-number="442"></td>
        <td id="LC442" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L443" class="blob-num js-line-number" data-line-number="443"></td>
        <td id="LC443" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L444" class="blob-num js-line-number" data-line-number="444"></td>
        <td id="LC444" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L445" class="blob-num js-line-number" data-line-number="445"></td>
        <td id="LC445" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L446" class="blob-num js-line-number" data-line-number="446"></td>
        <td id="LC446" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L447" class="blob-num js-line-number" data-line-number="447"></td>
        <td id="LC447" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L448" class="blob-num js-line-number" data-line-number="448"></td>
        <td id="LC448" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L449" class="blob-num js-line-number" data-line-number="449"></td>
        <td id="LC449" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L450" class="blob-num js-line-number" data-line-number="450"></td>
        <td id="LC450" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">11</span>: <span class="pl-c"><span class="pl-c">//</span> was 34</span></td>
      </tr>
      <tr>
        <td id="L451" class="blob-num js-line-number" data-line-number="451"></td>
        <td id="LC451" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> extra modes use pulse or input bit as length of SR controller: see mode 42 below</span></td>
      </tr>
      <tr>
        <td id="L452" class="blob-num js-line-number" data-line-number="452"></td>
        <td id="LC452" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>/ length thing	</span></td>
      </tr>
      <tr>
        <td id="L453" class="blob-num js-line-number" data-line-number="453"></td>
        <td id="LC453" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L454" class="blob-num js-line-number" data-line-number="454"></td>
        <td id="LC454" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L455" class="blob-num js-line-number" data-line-number="455"></td>
        <td id="LC455" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">31</span>) lcount=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L456" class="blob-num js-line-number" data-line-number="456"></td>
        <td id="LC456" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) {</td>
      </tr>
      <tr>
        <td id="L457" class="blob-num js-line-number" data-line-number="457"></td>
        <td id="LC457" class="blob-code blob-code-inner js-file-line">	SRlengthl=lcount;</td>
      </tr>
      <tr>
        <td id="L458" class="blob-num js-line-number" data-line-number="458"></td>
        <td id="LC458" class="blob-code blob-code-inner js-file-line">	lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthl/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L459" class="blob-num js-line-number" data-line-number="459"></td>
        <td id="LC459" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L460" class="blob-num js-line-number" data-line-number="460"></td>
        <td id="LC460" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as mode 3::::</span></td>
      </tr>
      <tr>
        <td id="L461" class="blob-num js-line-number" data-line-number="461"></td>
        <td id="LC461" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L462" class="blob-num js-line-number" data-line-number="462"></td>
        <td id="LC462" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L463" class="blob-num js-line-number" data-line-number="463"></td>
        <td id="LC463" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L464" class="blob-num js-line-number" data-line-number="464"></td>
        <td id="LC464" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L465" class="blob-num js-line-number" data-line-number="465"></td>
        <td id="LC465" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L466" class="blob-num js-line-number" data-line-number="466"></td>
        <td id="LC466" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L467" class="blob-num js-line-number" data-line-number="467"></td>
        <td id="LC467" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L468" class="blob-num js-line-number" data-line-number="468"></td>
        <td id="LC468" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L469" class="blob-num js-line-number" data-line-number="469"></td>
        <td id="LC469" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L470" class="blob-num js-line-number" data-line-number="470"></td>
        <td id="LC470" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L471" class="blob-num js-line-number" data-line-number="471"></td>
        <td id="LC471" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">12</span>: <span class="pl-c"><span class="pl-c">//</span> was 35</span></td>
      </tr>
      <tr>
        <td id="L472" class="blob-num js-line-number" data-line-number="472"></td>
        <td id="LC472" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L473" class="blob-num js-line-number" data-line-number="473"></td>
        <td id="LC473" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> can use input bit as length of either SR = here is regularSR</span></td>
      </tr>
      <tr>
        <td id="L474" class="blob-num js-line-number" data-line-number="474"></td>
        <td id="LC474" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> works well</span></td>
      </tr>
      <tr>
        <td id="L475" class="blob-num js-line-number" data-line-number="475"></td>
        <td id="LC475" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L476" class="blob-num js-line-number" data-line-number="476"></td>
        <td id="LC476" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">31</span>) lcount=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L477" class="blob-num js-line-number" data-line-number="477"></td>
        <td id="LC477" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) {</td>
      </tr>
      <tr>
        <td id="L478" class="blob-num js-line-number" data-line-number="478"></td>
        <td id="LC478" class="blob-code blob-code-inner js-file-line">	  SRlengthl=lcount;</td>
      </tr>
      <tr>
        <td id="L479" class="blob-num js-line-number" data-line-number="479"></td>
        <td id="LC479" class="blob-code blob-code-inner js-file-line">	  lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthl/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L480" class="blob-num js-line-number" data-line-number="480"></td>
        <td id="LC480" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L481" class="blob-num js-line-number" data-line-number="481"></td>
        <td id="LC481" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L482" class="blob-num js-line-number" data-line-number="482"></td>
        <td id="LC482" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerxl==<span class="pl-c1">0</span>) shift_registerxl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L483" class="blob-num js-line-number" data-line-number="483"></td>
        <td id="LC483" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L484" class="blob-num js-line-number" data-line-number="484"></td>
        <td id="LC484" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerxl &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L485" class="blob-num js-line-number" data-line-number="485"></td>
        <td id="LC485" class="blob-code blob-code-inner js-file-line">	shift_registerxl = (shift_registerxl&lt;&lt;<span class="pl-c1">1</span>) + bitl; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerxl = (shift_registerx&lt;&lt;1) + (bitl | !(GPIOB-&gt;IDR &amp; 0x0040)); </span></td>
      </tr>
      <tr>
        <td id="L486" class="blob-num js-line-number" data-line-number="486"></td>
        <td id="LC486" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L487" class="blob-num js-line-number" data-line-number="487"></td>
        <td id="LC487" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bitl with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L488" class="blob-num js-line-number" data-line-number="488"></td>
        <td id="LC488" class="blob-code blob-code-inner js-file-line">	  bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L489" class="blob-num js-line-number" data-line-number="489"></td>
        <td id="LC489" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L490" class="blob-num js-line-number" data-line-number="490"></td>
        <td id="LC490" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L491" class="blob-num js-line-number" data-line-number="491"></td>
        <td id="LC491" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L492" class="blob-num js-line-number" data-line-number="492"></td>
        <td id="LC492" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L493" class="blob-num js-line-number" data-line-number="493"></td>
        <td id="LC493" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L494" class="blob-num js-line-number" data-line-number="494"></td>
        <td id="LC494" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L495" class="blob-num js-line-number" data-line-number="495"></td>
        <td id="LC495" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L496" class="blob-num js-line-number" data-line-number="496"></td>
        <td id="LC496" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L497" class="blob-num js-line-number" data-line-number="497"></td>
        <td id="LC497" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L498" class="blob-num js-line-number" data-line-number="498"></td>
        <td id="LC498" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L499" class="blob-num js-line-number" data-line-number="499"></td>
        <td id="LC499" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">13</span>: <span class="pl-c"><span class="pl-c">//</span> was 37</span></td>
      </tr>
      <tr>
        <td id="L500" class="blob-num js-line-number" data-line-number="500"></td>
        <td id="LC500" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L501" class="blob-num js-line-number" data-line-number="501"></td>
        <td id="LC501" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> with input bit or&#39;ed in</span></td>
      </tr>
      <tr>
        <td id="L502" class="blob-num js-line-number" data-line-number="502"></td>
        <td id="LC502" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerxl==<span class="pl-c1">0</span>) shift_registerxl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L503" class="blob-num js-line-number" data-line-number="503"></td>
        <td id="LC503" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L504" class="blob-num js-line-number" data-line-number="504"></td>
        <td id="LC504" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerxl &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L505" class="blob-num js-line-number" data-line-number="505"></td>
        <td id="LC505" class="blob-code blob-code-inner js-file-line">	shift_registerxl = (shift_registerxl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)); </td>
      </tr>
      <tr>
        <td id="L506" class="blob-num js-line-number" data-line-number="506"></td>
        <td id="LC506" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L507" class="blob-num js-line-number" data-line-number="507"></td>
        <td id="LC507" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bitl with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L508" class="blob-num js-line-number" data-line-number="508"></td>
        <td id="LC508" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L509" class="blob-num js-line-number" data-line-number="509"></td>
        <td id="LC509" class="blob-code blob-code-inner js-file-line">	  bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L510" class="blob-num js-line-number" data-line-number="510"></td>
        <td id="LC510" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L511" class="blob-num js-line-number" data-line-number="511"></td>
        <td id="LC511" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L512" class="blob-num js-line-number" data-line-number="512"></td>
        <td id="LC512" class="blob-code blob-code-inner js-file-line">	  </td>
      </tr>
      <tr>
        <td id="L513" class="blob-num js-line-number" data-line-number="513"></td>
        <td id="LC513" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L514" class="blob-num js-line-number" data-line-number="514"></td>
        <td id="LC514" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L515" class="blob-num js-line-number" data-line-number="515"></td>
        <td id="LC515" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L516" class="blob-num js-line-number" data-line-number="516"></td>
        <td id="LC516" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L517" class="blob-num js-line-number" data-line-number="517"></td>
        <td id="LC517" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L518" class="blob-num js-line-number" data-line-number="518"></td>
        <td id="LC518" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L519" class="blob-num js-line-number" data-line-number="519"></td>
        <td id="LC519" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L520" class="blob-num js-line-number" data-line-number="520"></td>
        <td id="LC520" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L521" class="blob-num js-line-number" data-line-number="521"></td>
        <td id="LC521" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">14</span>: <span class="pl-c"><span class="pl-c">//</span> was 39</span></td>
      </tr>
      <tr>
        <td id="L522" class="blob-num js-line-number" data-line-number="522"></td>
        <td id="LC522" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> as above but LFSR?</span></td>
      </tr>
      <tr>
        <td id="L523" class="blob-num js-line-number" data-line-number="523"></td>
        <td id="LC523" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> working/.tested</span></td>
      </tr>
      <tr>
        <td id="L524" class="blob-num js-line-number" data-line-number="524"></td>
        <td id="LC524" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) togglel^=<span class="pl-c1">1</span>; </td>
      </tr>
      <tr>
        <td id="L525" class="blob-num js-line-number" data-line-number="525"></td>
        <td id="LC525" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L526" class="blob-num js-line-number" data-line-number="526"></td>
        <td id="LC526" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (togglel)</td>
      </tr>
      <tr>
        <td id="L527" class="blob-num js-line-number" data-line-number="527"></td>
        <td id="LC527" class="blob-code blob-code-inner js-file-line">	  {</td>
      </tr>
      <tr>
        <td id="L528" class="blob-num js-line-number" data-line-number="528"></td>
        <td id="LC528" class="blob-code blob-code-inner js-file-line">	    <span class="pl-k">if</span> (shift_registerl==<span class="pl-c1">0</span>) shift_registerl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L529" class="blob-num js-line-number" data-line-number="529"></td>
        <td id="LC529" class="blob-code blob-code-inner js-file-line">	    bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">0</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">1</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">2</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L530" class="blob-num js-line-number" data-line-number="530"></td>
        <td id="LC530" class="blob-code blob-code-inner js-file-line">	    shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>));  </td>
      </tr>
      <tr>
        <td id="L531" class="blob-num js-line-number" data-line-number="531"></td>
        <td id="LC531" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L532" class="blob-num js-line-number" data-line-number="532"></td>
        <td id="LC532" class="blob-code blob-code-inner js-file-line">	    <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L533" class="blob-num js-line-number" data-line-number="533"></td>
        <td id="LC533" class="blob-code blob-code-inner js-file-line">	    <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L534" class="blob-num js-line-number" data-line-number="534"></td>
        <td id="LC534" class="blob-code blob-code-inner js-file-line">	    <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L535" class="blob-num js-line-number" data-line-number="535"></td>
        <td id="LC535" class="blob-code blob-code-inner js-file-line">	    <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L536" class="blob-num js-line-number" data-line-number="536"></td>
        <td id="LC536" class="blob-code blob-code-inner js-file-line">	  }</td>
      </tr>
      <tr>
        <td id="L537" class="blob-num js-line-number" data-line-number="537"></td>
        <td id="LC537" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L538" class="blob-num js-line-number" data-line-number="538"></td>
        <td id="LC538" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L539" class="blob-num js-line-number" data-line-number="539"></td>
        <td id="LC539" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">15</span>: <span class="pl-c"><span class="pl-c">//</span> was 40</span></td>
      </tr>
      <tr>
        <td id="L540" class="blob-num js-line-number" data-line-number="540"></td>
        <td id="LC540" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> pulse in means a divide/flip flop</span></td>
      </tr>
      <tr>
        <td id="L541" class="blob-num js-line-number" data-line-number="541"></td>
        <td id="LC541" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> TESTED/WORKING but is only that divide on one bit..FIXED TESTED</span></td>
      </tr>
      <tr>
        <td id="L542" class="blob-num js-line-number" data-line-number="542"></td>
        <td id="LC542" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L543" class="blob-num js-line-number" data-line-number="543"></td>
        <td id="LC543" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L544" class="blob-num js-line-number" data-line-number="544"></td>
        <td id="LC544" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L545" class="blob-num js-line-number" data-line-number="545"></td>
        <td id="LC545" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L546" class="blob-num js-line-number" data-line-number="546"></td>
        <td id="LC546" class="blob-code blob-code-inner js-file-line">	new_statel[<span class="pl-c1">0</span>]=bitl;</td>
      </tr>
      <tr>
        <td id="L547" class="blob-num js-line-number" data-line-number="547"></td>
        <td id="LC547" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">0</span> &amp;&amp; new_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">1</span>) flippedl[<span class="pl-c1">0</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L548" class="blob-num js-line-number" data-line-number="548"></td>
        <td id="LC548" class="blob-code blob-code-inner js-file-line">	prev_statel[<span class="pl-c1">0</span>]=new_statel[<span class="pl-c1">0</span>];	</td>
      </tr>
      <tr>
        <td id="L549" class="blob-num js-line-number" data-line-number="549"></td>
        <td id="LC549" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L550" class="blob-num js-line-number" data-line-number="550"></td>
        <td id="LC550" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) new_statel[<span class="pl-c1">1</span>]=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L551" class="blob-num js-line-number" data-line-number="551"></td>
        <td id="LC551" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> new_statel[<span class="pl-c1">1</span>]=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L552" class="blob-num js-line-number" data-line-number="552"></td>
        <td id="LC552" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_statel[<span class="pl-c1">1</span>]==<span class="pl-c1">1</span> &amp;&amp; new_statel[<span class="pl-c1">1</span>]==<span class="pl-c1">1</span>) flippedl[<span class="pl-c1">1</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L553" class="blob-num js-line-number" data-line-number="553"></td>
        <td id="LC553" class="blob-code blob-code-inner js-file-line">	prev_statel[<span class="pl-c1">1</span>]=new_statel[<span class="pl-c1">1</span>];	</td>
      </tr>
      <tr>
        <td id="L554" class="blob-num js-line-number" data-line-number="554"></td>
        <td id="LC554" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L555" class="blob-num js-line-number" data-line-number="555"></td>
        <td id="LC555" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0020</span>)) {</td>
      </tr>
      <tr>
        <td id="L556" class="blob-num js-line-number" data-line-number="556"></td>
        <td id="LC556" class="blob-code blob-code-inner js-file-line">	  bitl=flippedl[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L557" class="blob-num js-line-number" data-line-number="557"></td>
        <td id="LC557" class="blob-code blob-code-inner js-file-line">	  tmp=flippedl[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L558" class="blob-num js-line-number" data-line-number="558"></td>
        <td id="LC558" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L559" class="blob-num js-line-number" data-line-number="559"></td>
        <td id="LC559" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> tmp=new_statel[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L560" class="blob-num js-line-number" data-line-number="560"></td>
        <td id="LC560" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L561" class="blob-num js-line-number" data-line-number="561"></td>
        <td id="LC561" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L562" class="blob-num js-line-number" data-line-number="562"></td>
        <td id="LC562" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L563" class="blob-num js-line-number" data-line-number="563"></td>
        <td id="LC563" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (tmp) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L564" class="blob-num js-line-number" data-line-number="564"></td>
        <td id="LC564" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L565" class="blob-num js-line-number" data-line-number="565"></td>
        <td id="LC565" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L566" class="blob-num js-line-number" data-line-number="566"></td>
        <td id="LC566" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L567" class="blob-num js-line-number" data-line-number="567"></td>
        <td id="LC567" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> /END of LF SR side/..................................................................................................................    </span></td>
      </tr>
      <tr>
        <td id="L568" class="blob-num js-line-number" data-line-number="568"></td>
        <td id="LC568" class="blob-code blob-code-inner js-file-line">	    }</td>
      </tr>
      <tr>
        <td id="L569" class="blob-num js-line-number" data-line-number="569"></td>
        <td id="LC569" class="blob-code blob-code-inner js-file-line">    }</td>
      </tr>
      <tr>
        <td id="L570" class="blob-num js-line-number" data-line-number="570"></td>
        <td id="LC570" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span>..........................................</span></td>
      </tr>
      <tr>
        <td id="L571" class="blob-num js-line-number" data-line-number="571"></td>
        <td id="LC571" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span>//////////////////////////////////////////-&gt;&gt;&gt;    /// high side</span></td>
      </tr>
      <tr>
        <td id="L572" class="blob-num js-line-number" data-line-number="572"></td>
        <td id="LC572" class="blob-code blob-code-inner js-file-line">        counterh++;</td>
      </tr>
      <tr>
        <td id="L573" class="blob-num js-line-number" data-line-number="573"></td>
        <td id="LC573" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span> (counterh&gt;speedhh){</td>
      </tr>
      <tr>
        <td id="L574" class="blob-num js-line-number" data-line-number="574"></td>
        <td id="LC574" class="blob-code blob-code-inner js-file-line">      counterh=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L575" class="blob-num js-line-number" data-line-number="575"></td>
        <td id="LC575" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L576" class="blob-num js-line-number" data-line-number="576"></td>
        <td id="LC576" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> *CV_HF: 0, 1, 2, 3, 4, 7, 9, 23, 25, 26, 28, 29, 34, 35, 36, 41*</span></td>
      </tr>
      <tr>
        <td id="L577" class="blob-num js-line-number" data-line-number="577"></td>
        <td id="LC577" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L578" class="blob-num js-line-number" data-line-number="578"></td>
        <td id="LC578" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      HF_TIM2_modes[modehsr](); // TEST for function pointer approach</span></td>
      </tr>
      <tr>
        <td id="L579" class="blob-num js-line-number" data-line-number="579"></td>
        <td id="LC579" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">switch</span>(modehsr){	 <span class="pl-c"><span class="pl-c">//</span> SWITCH approach</span></td>
      </tr>
      <tr>
        <td id="L580" class="blob-num js-line-number" data-line-number="580"></td>
        <td id="LC580" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">0</span>:</td>
      </tr>
      <tr>
        <td id="L581" class="blob-num js-line-number" data-line-number="581"></td>
        <td id="LC581" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 0- pulse clock in (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)</span></td>
      </tr>
      <tr>
        <td id="L582" class="blob-num js-line-number" data-line-number="582"></td>
        <td id="LC582" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L583" class="blob-num js-line-number" data-line-number="583"></td>
        <td id="LC583" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L584" class="blob-num js-line-number" data-line-number="584"></td>
        <td id="LC584" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)); <span class="pl-c"><span class="pl-c">//</span> 0x0080 is clock bit in!</span></td>
      </tr>
      <tr>
        <td id="L585" class="blob-num js-line-number" data-line-number="585"></td>
        <td id="LC585" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith | (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>))); </td>
      </tr>
      <tr>
        <td id="L586" class="blob-num js-line-number" data-line-number="586"></td>
        <td id="LC586" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L587" class="blob-num js-line-number" data-line-number="587"></td>
        <td id="LC587" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> shift register bits output - inverted on PC13 and 14;</span></td>
      </tr>
      <tr>
        <td id="L588" class="blob-num js-line-number" data-line-number="588"></td>
        <td id="LC588" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L589" class="blob-num js-line-number" data-line-number="589"></td>
        <td id="LC589" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L590" class="blob-num js-line-number" data-line-number="590"></td>
        <td id="LC590" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L591" class="blob-num js-line-number" data-line-number="591"></td>
        <td id="LC591" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L592" class="blob-num js-line-number" data-line-number="592"></td>
        <td id="LC592" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L593" class="blob-num js-line-number" data-line-number="593"></td>
        <td id="LC593" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L594" class="blob-num js-line-number" data-line-number="594"></td>
        <td id="LC594" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">1</span>: </td>
      </tr>
      <tr>
        <td id="L595" class="blob-num js-line-number" data-line-number="595"></td>
        <td id="LC595" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)</span></td>
      </tr>
      <tr>
        <td id="L596" class="blob-num js-line-number" data-line-number="596"></td>
        <td id="LC596" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L597" class="blob-num js-line-number" data-line-number="597"></td>
        <td id="LC597" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L598" class="blob-num js-line-number" data-line-number="598"></td>
        <td id="LC598" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>));</td>
      </tr>
      <tr>
        <td id="L599" class="blob-num js-line-number" data-line-number="599"></td>
        <td id="LC599" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((bith ^ !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)));</td>
      </tr>
      <tr>
        <td id="L600" class="blob-num js-line-number" data-line-number="600"></td>
        <td id="LC600" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L601" class="blob-num js-line-number" data-line-number="601"></td>
        <td id="LC601" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L602" class="blob-num js-line-number" data-line-number="602"></td>
        <td id="LC602" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L603" class="blob-num js-line-number" data-line-number="603"></td>
        <td id="LC603" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L604" class="blob-num js-line-number" data-line-number="604"></td>
        <td id="LC604" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L605" class="blob-num js-line-number" data-line-number="605"></td>
        <td id="LC605" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L606" class="blob-num js-line-number" data-line-number="606"></td>
        <td id="LC606" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L607" class="blob-num js-line-number" data-line-number="607"></td>
        <td id="LC607" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">2</span>: </td>
      </tr>
      <tr>
        <td id="L608" class="blob-num js-line-number" data-line-number="608"></td>
        <td id="LC608" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse</span></td>
      </tr>
      <tr>
        <td id="L609" class="blob-num js-line-number" data-line-number="609"></td>
        <td id="LC609" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L610" class="blob-num js-line-number" data-line-number="610"></td>
        <td id="LC610" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;SRlengthh) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L611" class="blob-num js-line-number" data-line-number="611"></td>
        <td id="LC611" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L612" class="blob-num js-line-number" data-line-number="612"></td>
        <td id="LC612" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L613" class="blob-num js-line-number" data-line-number="613"></td>
        <td id="LC613" class="blob-code blob-code-inner js-file-line">	shift_registerh= (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>));</td>
      </tr>
      <tr>
        <td id="L614" class="blob-num js-line-number" data-line-number="614"></td>
        <td id="LC614" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L615" class="blob-num js-line-number" data-line-number="615"></td>
        <td id="LC615" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) shift_registerh ^= (<span class="pl-c1">1</span>&lt;&lt;hcount); <span class="pl-c"><span class="pl-c">//</span> if we have pulse and hcount then flip that bit inside SR... rest all the same...</span></td>
      </tr>
      <tr>
        <td id="L616" class="blob-num js-line-number" data-line-number="616"></td>
        <td id="LC616" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L617" class="blob-num js-line-number" data-line-number="617"></td>
        <td id="LC617" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L618" class="blob-num js-line-number" data-line-number="618"></td>
        <td id="LC618" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L619" class="blob-num js-line-number" data-line-number="619"></td>
        <td id="LC619" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L620" class="blob-num js-line-number" data-line-number="620"></td>
        <td id="LC620" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L621" class="blob-num js-line-number" data-line-number="621"></td>
        <td id="LC621" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L622" class="blob-num js-line-number" data-line-number="622"></td>
        <td id="LC622" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L623" class="blob-num js-line-number" data-line-number="623"></td>
        <td id="LC623" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">3</span>: <span class="pl-c"><span class="pl-c">//</span>* </span></td>
      </tr>
      <tr>
        <td id="L624" class="blob-num js-line-number" data-line-number="624"></td>
        <td id="LC624" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)</span></td>
      </tr>
      <tr>
        <td id="L625" class="blob-num js-line-number" data-line-number="625"></td>
        <td id="LC625" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L626" class="blob-num js-line-number" data-line-number="626"></td>
        <td id="LC626" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L627" class="blob-num js-line-number" data-line-number="627"></td>
        <td id="LC627" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L628" class="blob-num js-line-number" data-line-number="628"></td>
        <td id="LC628" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L629" class="blob-num js-line-number" data-line-number="629"></td>
        <td id="LC629" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L630" class="blob-num js-line-number" data-line-number="630"></td>
        <td id="LC630" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L631" class="blob-num js-line-number" data-line-number="631"></td>
        <td id="LC631" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L632" class="blob-num js-line-number" data-line-number="632"></td>
        <td id="LC632" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L633" class="blob-num js-line-number" data-line-number="633"></td>
        <td id="LC633" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L634" class="blob-num js-line-number" data-line-number="634"></td>
        <td id="LC634" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L635" class="blob-num js-line-number" data-line-number="635"></td>
        <td id="LC635" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">4</span>: </td>
      </tr>
      <tr>
        <td id="L636" class="blob-num js-line-number" data-line-number="636"></td>
        <td id="LC636" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 4- parity for loopback XOR is determined by pulsed bits in -&gt; select bits with pulse and queue </span></td>
      </tr>
      <tr>
        <td id="L637" class="blob-num js-line-number" data-line-number="637"></td>
        <td id="LC637" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L638" class="blob-num js-line-number" data-line-number="638"></td>
        <td id="LC638" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;SRlengthh) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L639" class="blob-num js-line-number" data-line-number="639"></td>
        <td id="LC639" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) {</td>
      </tr>
      <tr>
        <td id="L640" class="blob-num js-line-number" data-line-number="640"></td>
        <td id="LC640" class="blob-code blob-code-inner js-file-line">	  hstack[<span class="pl-c1">3</span>]=hstack[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L641" class="blob-num js-line-number" data-line-number="641"></td>
        <td id="LC641" class="blob-code blob-code-inner js-file-line">	  hstack[<span class="pl-c1">2</span>]=hstack[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L642" class="blob-num js-line-number" data-line-number="642"></td>
        <td id="LC642" class="blob-code blob-code-inner js-file-line">	  hstack[<span class="pl-c1">1</span>]=hstack[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L643" class="blob-num js-line-number" data-line-number="643"></td>
        <td id="LC643" class="blob-code blob-code-inner js-file-line">	  hstack[<span class="pl-c1">0</span>]=hcount+<span class="pl-c1">1</span>; <span class="pl-c"><span class="pl-c">//</span> bump it on to the hstack</span></td>
      </tr>
      <tr>
        <td id="L644" class="blob-num js-line-number" data-line-number="644"></td>
        <td id="LC644" class="blob-code blob-code-inner js-file-line">	}	  </td>
      </tr>
      <tr>
        <td id="L645" class="blob-num js-line-number" data-line-number="645"></td>
        <td id="LC645" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L646" class="blob-num js-line-number" data-line-number="646"></td>
        <td id="LC646" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerh &gt;&gt; hstack[<span class="pl-c1">0</span>]) ^ (shift_registerh &gt;&gt; hstack[<span class="pl-c1">1</span>]) ^ (shift_registerh &gt;&gt; hstack[<span class="pl-c1">2</span>]) ^ (shift_registerh &gt;&gt; hstack[<span class="pl-c1">3</span>])) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L647" class="blob-num js-line-number" data-line-number="647"></td>
        <td id="LC647" class="blob-code blob-code-inner js-file-line">	shift_registerh= (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)); <span class="pl-c"><span class="pl-c">//</span> TESTY - to OR in new bit or not?</span></td>
      </tr>
      <tr>
        <td id="L648" class="blob-num js-line-number" data-line-number="648"></td>
        <td id="LC648" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L649" class="blob-num js-line-number" data-line-number="649"></td>
        <td id="LC649" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L650" class="blob-num js-line-number" data-line-number="650"></td>
        <td id="LC650" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L651" class="blob-num js-line-number" data-line-number="651"></td>
        <td id="LC651" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L652" class="blob-num js-line-number" data-line-number="652"></td>
        <td id="LC652" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L653" class="blob-num js-line-number" data-line-number="653"></td>
        <td id="LC653" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L654" class="blob-num js-line-number" data-line-number="654"></td>
        <td id="LC654" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L655" class="blob-num js-line-number" data-line-number="655"></td>
        <td id="LC655" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">5</span>: <span class="pl-c"><span class="pl-c">//</span> was 7</span></td>
      </tr>
      <tr>
        <td id="L656" class="blob-num js-line-number" data-line-number="656"></td>
        <td id="LC656" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?</span></td>
      </tr>
      <tr>
        <td id="L657" class="blob-num js-line-number" data-line-number="657"></td>
        <td id="LC657" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> no use of in bit</span></td>
      </tr>
      <tr>
        <td id="L658" class="blob-num js-line-number" data-line-number="658"></td>
        <td id="LC658" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> !note: swop l and h when port to low!</span></td>
      </tr>
      <tr>
        <td id="L659" class="blob-num js-line-number" data-line-number="659"></td>
        <td id="LC659" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L660" class="blob-num js-line-number" data-line-number="660"></td>
        <td id="LC660" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">7</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L661" class="blob-num js-line-number" data-line-number="661"></td>
        <td id="LC661" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) probh^=(<span class="pl-c1">1</span>&lt;&lt;hcount);</td>
      </tr>
      <tr>
        <td id="L662" class="blob-num js-line-number" data-line-number="662"></td>
        <td id="LC662" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L663" class="blob-num js-line-number" data-line-number="663"></td>
        <td id="LC663" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); </td>
      </tr>
      <tr>
        <td id="L664" class="blob-num js-line-number" data-line-number="664"></td>
        <td id="LC664" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L665" class="blob-num js-line-number" data-line-number="665"></td>
        <td id="LC665" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L666" class="blob-num js-line-number" data-line-number="666"></td>
        <td id="LC666" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L667" class="blob-num js-line-number" data-line-number="667"></td>
        <td id="LC667" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L668" class="blob-num js-line-number" data-line-number="668"></td>
        <td id="LC668" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L669" class="blob-num js-line-number" data-line-number="669"></td>
        <td id="LC669" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L670" class="blob-num js-line-number" data-line-number="670"></td>
        <td id="LC670" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L671" class="blob-num js-line-number" data-line-number="671"></td>
        <td id="LC671" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L672" class="blob-num js-line-number" data-line-number="672"></td>
        <td id="LC672" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">6</span>:  <span class="pl-c"><span class="pl-c">//</span> was 9</span></td>
      </tr>
      <tr>
        <td id="L673" class="blob-num js-line-number" data-line-number="673"></td>
        <td id="LC673" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!</span></td>
      </tr>
      <tr>
        <td id="L674" class="blob-num js-line-number" data-line-number="674"></td>
        <td id="LC674" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh==<span class="pl-c1">0</span>) shift_registerh=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L675" class="blob-num js-line-number" data-line-number="675"></td>
        <td id="LC675" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">0</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">1</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">2</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L676" class="blob-num js-line-number" data-line-number="676"></td>
        <td id="LC676" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L677" class="blob-num js-line-number" data-line-number="677"></td>
        <td id="LC677" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)); </td>
      </tr>
      <tr>
        <td id="L678" class="blob-num js-line-number" data-line-number="678"></td>
        <td id="LC678" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L679" class="blob-num js-line-number" data-line-number="679"></td>
        <td id="LC679" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L680" class="blob-num js-line-number" data-line-number="680"></td>
        <td id="LC680" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L681" class="blob-num js-line-number" data-line-number="681"></td>
        <td id="LC681" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L682" class="blob-num js-line-number" data-line-number="682"></td>
        <td id="LC682" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L683" class="blob-num js-line-number" data-line-number="683"></td>
        <td id="LC683" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L684" class="blob-num js-line-number" data-line-number="684"></td>
        <td id="LC684" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L685" class="blob-num js-line-number" data-line-number="685"></td>
        <td id="LC685" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">7</span>: <span class="pl-c"><span class="pl-c">//</span> was 23 --&gt; experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L686" class="blob-num js-line-number" data-line-number="686"></td>
        <td id="LC686" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> shifting the array of LFSR taps = ghost_tapsH on the high side</span></td>
      </tr>
      <tr>
        <td id="L687" class="blob-num js-line-number" data-line-number="687"></td>
        <td id="LC687" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> clock pulse shifts one selected by pulse </span></td>
      </tr>
      <tr>
        <td id="L688" class="blob-num js-line-number" data-line-number="688"></td>
        <td id="LC688" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) hcount++;</td>
      </tr>
      <tr>
        <td id="L689" class="blob-num js-line-number" data-line-number="689"></td>
        <td id="LC689" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">3</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L690" class="blob-num js-line-number" data-line-number="690"></td>
        <td id="LC690" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)) {</td>
      </tr>
      <tr>
        <td id="L691" class="blob-num js-line-number" data-line-number="691"></td>
        <td id="LC691" class="blob-code blob-code-inner js-file-line">	  ghost_tapsH[SRlengthh][hcount+<span class="pl-c1">1</span>]+=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L692" class="blob-num js-line-number" data-line-number="692"></td>
        <td id="LC692" class="blob-code blob-code-inner js-file-line">	  ghost_tapsH[SRlengthh][hcount+<span class="pl-c1">1</span>]%=SRlengthh;</td>
      </tr>
      <tr>
        <td id="L693" class="blob-num js-line-number" data-line-number="693"></td>
        <td id="LC693" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L694" class="blob-num js-line-number" data-line-number="694"></td>
        <td id="LC694" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L695" class="blob-num js-line-number" data-line-number="695"></td>
        <td id="LC695" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh==<span class="pl-c1">0</span>) shift_registerh=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L696" class="blob-num js-line-number" data-line-number="696"></td>
        <td id="LC696" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerh &gt;&gt; (ghost_tapsH[SRlengthh][<span class="pl-c1">0</span>])) ^ (shift_registerh &gt;&gt; (ghost_tapsH[SRlengthh][<span class="pl-c1">1</span>])) ^ (shift_registerh &gt;&gt; (ghost_tapsH[SRlengthh][<span class="pl-c1">2</span>])) ^ (shift_registerh &gt;&gt; (ghost_tapsH[SRlengthh][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L697" class="blob-num js-line-number" data-line-number="697"></td>
        <td id="LC697" class="blob-code blob-code-inner js-file-line">	shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L698" class="blob-num js-line-number" data-line-number="698"></td>
        <td id="LC698" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L699" class="blob-num js-line-number" data-line-number="699"></td>
        <td id="LC699" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L700" class="blob-num js-line-number" data-line-number="700"></td>
        <td id="LC700" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L701" class="blob-num js-line-number" data-line-number="701"></td>
        <td id="LC701" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L702" class="blob-num js-line-number" data-line-number="702"></td>
        <td id="LC702" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L703" class="blob-num js-line-number" data-line-number="703"></td>
        <td id="LC703" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L704" class="blob-num js-line-number" data-line-number="704"></td>
        <td id="LC704" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L705" class="blob-num js-line-number" data-line-number="705"></td>
        <td id="LC705" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">8</span>: <span class="pl-c"><span class="pl-c">//</span> was 25</span></td>
      </tr>
      <tr>
        <td id="L706" class="blob-num js-line-number" data-line-number="706"></td>
        <td id="LC706" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L707" class="blob-num js-line-number" data-line-number="707"></td>
        <td id="LC707" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L708" class="blob-num js-line-number" data-line-number="708"></td>
        <td id="LC708" class="blob-code blob-code-inner js-file-line">	shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith | (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)));</td>
      </tr>
      <tr>
        <td id="L709" class="blob-num js-line-number" data-line-number="709"></td>
        <td id="LC709" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> do the loop back in</span></td>
      </tr>
      <tr>
        <td id="L710" class="blob-num js-line-number" data-line-number="710"></td>
        <td id="LC710" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) hcount++;</td>
      </tr>
      <tr>
        <td id="L711" class="blob-num js-line-number" data-line-number="711"></td>
        <td id="LC711" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;SRlengthh) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L712" class="blob-num js-line-number" data-line-number="712"></td>
        <td id="LC712" class="blob-code blob-code-inner js-file-line">	tmp = (shift_registerh&gt;&gt;hcount) &amp; <span class="pl-c1">0x01</span>;</td>
      </tr>
      <tr>
        <td id="L713" class="blob-num js-line-number" data-line-number="713"></td>
        <td id="LC713" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> where to put that bit? XOR it with first bit</span></td>
      </tr>
      <tr>
        <td id="L714" class="blob-num js-line-number" data-line-number="714"></td>
        <td id="LC714" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> ( (shift_registerh &amp; <span class="pl-c1">0x01</span>) ^ tmp) shift_registerh |= <span class="pl-c1">0x01</span>;<span class="pl-c"><span class="pl-c">//</span> set the first bit</span></td>
      </tr>
      <tr>
        <td id="L715" class="blob-num js-line-number" data-line-number="715"></td>
        <td id="LC715" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh &amp;= ~(<span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> clear the first bit</span></td>
      </tr>
      <tr>
        <td id="L716" class="blob-num js-line-number" data-line-number="716"></td>
        <td id="LC716" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L717" class="blob-num js-line-number" data-line-number="717"></td>
        <td id="LC717" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L718" class="blob-num js-line-number" data-line-number="718"></td>
        <td id="LC718" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L719" class="blob-num js-line-number" data-line-number="719"></td>
        <td id="LC719" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L720" class="blob-num js-line-number" data-line-number="720"></td>
        <td id="LC720" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L721" class="blob-num js-line-number" data-line-number="721"></td>
        <td id="LC721" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L722" class="blob-num js-line-number" data-line-number="722"></td>
        <td id="LC722" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L723" class="blob-num js-line-number" data-line-number="723"></td>
        <td id="LC723" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">9</span>: <span class="pl-c"><span class="pl-c">//</span> was 26</span></td>
      </tr>
      <tr>
        <td id="L724" class="blob-num js-line-number" data-line-number="724"></td>
        <td id="LC724" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L725" class="blob-num js-line-number" data-line-number="725"></td>
        <td id="LC725" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> can use input bit as length of either SR</span></td>
      </tr>
      <tr>
        <td id="L726" class="blob-num js-line-number" data-line-number="726"></td>
        <td id="LC726" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> also can still use in clocking side of things</span></td>
      </tr>
      <tr>
        <td id="L727" class="blob-num js-line-number" data-line-number="727"></td>
        <td id="LC727" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> no use of input bit...</span></td>
      </tr>
      <tr>
        <td id="L728" class="blob-num js-line-number" data-line-number="728"></td>
        <td id="LC728" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L729" class="blob-num js-line-number" data-line-number="729"></td>
        <td id="LC729" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][0])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][1])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][2])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L730" class="blob-num js-line-number" data-line-number="730"></td>
        <td id="LC730" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L731" class="blob-num js-line-number" data-line-number="731"></td>
        <td id="LC731" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L732" class="blob-num js-line-number" data-line-number="732"></td>
        <td id="LC732" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L733" class="blob-num js-line-number" data-line-number="733"></td>
        <td id="LC733" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L734" class="blob-num js-line-number" data-line-number="734"></td>
        <td id="LC734" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L735" class="blob-num js-line-number" data-line-number="735"></td>
        <td id="LC735" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L736" class="blob-num js-line-number" data-line-number="736"></td>
        <td id="LC736" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L737" class="blob-num js-line-number" data-line-number="737"></td>
        <td id="LC737" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L738" class="blob-num js-line-number" data-line-number="738"></td>
        <td id="LC738" class="blob-code blob-code-inner js-file-line">	  </td>
      </tr>
      <tr>
        <td id="L739" class="blob-num js-line-number" data-line-number="739"></td>
        <td id="LC739" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L740" class="blob-num js-line-number" data-line-number="740"></td>
        <td id="LC740" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L741" class="blob-num js-line-number" data-line-number="741"></td>
        <td id="LC741" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L742" class="blob-num js-line-number" data-line-number="742"></td>
        <td id="LC742" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L743" class="blob-num js-line-number" data-line-number="743"></td>
        <td id="LC743" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L744" class="blob-num js-line-number" data-line-number="744"></td>
        <td id="LC744" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L745" class="blob-num js-line-number" data-line-number="745"></td>
        <td id="LC745" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L746" class="blob-num js-line-number" data-line-number="746"></td>
        <td id="LC746" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L747" class="blob-num js-line-number" data-line-number="747"></td>
        <td id="LC747" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">10</span>: <span class="pl-c"><span class="pl-c">//</span> was 28</span></td>
      </tr>
      <tr>
        <td id="L748" class="blob-num js-line-number" data-line-number="748"></td>
        <td id="LC748" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - as mode 26 but now we use 0x0080 bit also to see if we shift things...</span></td>
      </tr>
      <tr>
        <td id="L749" class="blob-num js-line-number" data-line-number="749"></td>
        <td id="LC749" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> no use of input bit... - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L750" class="blob-num js-line-number" data-line-number="750"></td>
        <td id="LC750" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L751" class="blob-num js-line-number" data-line-number="751"></td>
        <td id="LC751" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][0])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][1])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][2])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L752" class="blob-num js-line-number" data-line-number="752"></td>
        <td id="LC752" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L753" class="blob-num js-line-number" data-line-number="753"></td>
        <td id="LC753" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L754" class="blob-num js-line-number" data-line-number="754"></td>
        <td id="LC754" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L755" class="blob-num js-line-number" data-line-number="755"></td>
        <td id="LC755" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith &amp;&amp; !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>) ){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L756" class="blob-num js-line-number" data-line-number="756"></td>
        <td id="LC756" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L757" class="blob-num js-line-number" data-line-number="757"></td>
        <td id="LC757" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L758" class="blob-num js-line-number" data-line-number="758"></td>
        <td id="LC758" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L759" class="blob-num js-line-number" data-line-number="759"></td>
        <td id="LC759" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L760" class="blob-num js-line-number" data-line-number="760"></td>
        <td id="LC760" class="blob-code blob-code-inner js-file-line">	  </td>
      </tr>
      <tr>
        <td id="L761" class="blob-num js-line-number" data-line-number="761"></td>
        <td id="LC761" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L762" class="blob-num js-line-number" data-line-number="762"></td>
        <td id="LC762" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L763" class="blob-num js-line-number" data-line-number="763"></td>
        <td id="LC763" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L764" class="blob-num js-line-number" data-line-number="764"></td>
        <td id="LC764" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L765" class="blob-num js-line-number" data-line-number="765"></td>
        <td id="LC765" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L766" class="blob-num js-line-number" data-line-number="766"></td>
        <td id="LC766" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L767" class="blob-num js-line-number" data-line-number="767"></td>
        <td id="LC767" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L768" class="blob-num js-line-number" data-line-number="768"></td>
        <td id="LC768" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L769" class="blob-num js-line-number" data-line-number="769"></td>
        <td id="LC769" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">11</span>: <span class="pl-c"><span class="pl-c">//</span> was 29</span></td>
      </tr>
      <tr>
        <td id="L770" class="blob-num js-line-number" data-line-number="770"></td>
        <td id="LC770" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-&gt; our 3 options if we have a bit 0x0080</span></td>
      </tr>
      <tr>
        <td id="L771" class="blob-num js-line-number" data-line-number="771"></td>
        <td id="LC771" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L772" class="blob-num js-line-number" data-line-number="772"></td>
        <td id="LC772" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)){</td>
      </tr>
      <tr>
        <td id="L773" class="blob-num js-line-number" data-line-number="773"></td>
        <td id="LC773" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L774" class="blob-num js-line-number" data-line-number="774"></td>
        <td id="LC774" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L775" class="blob-num js-line-number" data-line-number="775"></td>
        <td id="LC775" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L776" class="blob-num js-line-number" data-line-number="776"></td>
        <td id="LC776" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L777" class="blob-num js-line-number" data-line-number="777"></td>
        <td id="LC777" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L778" class="blob-num js-line-number" data-line-number="778"></td>
        <td id="LC778" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L779" class="blob-num js-line-number" data-line-number="779"></td>
        <td id="LC779" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L780" class="blob-num js-line-number" data-line-number="780"></td>
        <td id="LC780" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L781" class="blob-num js-line-number" data-line-number="781"></td>
        <td id="LC781" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L782" class="blob-num js-line-number" data-line-number="782"></td>
        <td id="LC782" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L783" class="blob-num js-line-number" data-line-number="783"></td>
        <td id="LC783" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L784" class="blob-num js-line-number" data-line-number="784"></td>
        <td id="LC784" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">12</span>: <span class="pl-c"><span class="pl-c">//</span> was 34</span></td>
      </tr>
      <tr>
        <td id="L785" class="blob-num js-line-number" data-line-number="785"></td>
        <td id="LC785" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> extra modes use pulse or input bit as length of SR controller: see mode 42 below</span></td>
      </tr>
      <tr>
        <td id="L786" class="blob-num js-line-number" data-line-number="786"></td>
        <td id="LC786" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>/ length thing	</span></td>
      </tr>
      <tr>
        <td id="L787" class="blob-num js-line-number" data-line-number="787"></td>
        <td id="LC787" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L788" class="blob-num js-line-number" data-line-number="788"></td>
        <td id="LC788" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L789" class="blob-num js-line-number" data-line-number="789"></td>
        <td id="LC789" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">31</span>) hcount=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L790" class="blob-num js-line-number" data-line-number="790"></td>
        <td id="LC790" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) {</td>
      </tr>
      <tr>
        <td id="L791" class="blob-num js-line-number" data-line-number="791"></td>
        <td id="LC791" class="blob-code blob-code-inner js-file-line">	SRlengthh=hcount;</td>
      </tr>
      <tr>
        <td id="L792" class="blob-num js-line-number" data-line-number="792"></td>
        <td id="LC792" class="blob-code blob-code-inner js-file-line">	lengthbith=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthh/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L793" class="blob-num js-line-number" data-line-number="793"></td>
        <td id="LC793" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L794" class="blob-num js-line-number" data-line-number="794"></td>
        <td id="LC794" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as mode 3::::</span></td>
      </tr>
      <tr>
        <td id="L795" class="blob-num js-line-number" data-line-number="795"></td>
        <td id="LC795" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L796" class="blob-num js-line-number" data-line-number="796"></td>
        <td id="LC796" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L797" class="blob-num js-line-number" data-line-number="797"></td>
        <td id="LC797" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L798" class="blob-num js-line-number" data-line-number="798"></td>
        <td id="LC798" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L799" class="blob-num js-line-number" data-line-number="799"></td>
        <td id="LC799" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L800" class="blob-num js-line-number" data-line-number="800"></td>
        <td id="LC800" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L801" class="blob-num js-line-number" data-line-number="801"></td>
        <td id="LC801" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L802" class="blob-num js-line-number" data-line-number="802"></td>
        <td id="LC802" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L803" class="blob-num js-line-number" data-line-number="803"></td>
        <td id="LC803" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L804" class="blob-num js-line-number" data-line-number="804"></td>
        <td id="LC804" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L805" class="blob-num js-line-number" data-line-number="805"></td>
        <td id="LC805" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>///////////new /experimental</span></td>
      </tr>
      <tr>
        <td id="L806" class="blob-num js-line-number" data-line-number="806"></td>
        <td id="LC806" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L807" class="blob-num js-line-number" data-line-number="807"></td>
        <td id="LC807" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">13</span>: <span class="pl-c"><span class="pl-c">//</span> was 35</span></td>
      </tr>
      <tr>
        <td id="L808" class="blob-num js-line-number" data-line-number="808"></td>
        <td id="LC808" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L809" class="blob-num js-line-number" data-line-number="809"></td>
        <td id="LC809" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> can use input bit as length of either SR = here is regularSR</span></td>
      </tr>
      <tr>
        <td id="L810" class="blob-num js-line-number" data-line-number="810"></td>
        <td id="LC810" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> works well</span></td>
      </tr>
      <tr>
        <td id="L811" class="blob-num js-line-number" data-line-number="811"></td>
        <td id="LC811" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L812" class="blob-num js-line-number" data-line-number="812"></td>
        <td id="LC812" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">31</span>) hcount=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L813" class="blob-num js-line-number" data-line-number="813"></td>
        <td id="LC813" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) {</td>
      </tr>
      <tr>
        <td id="L814" class="blob-num js-line-number" data-line-number="814"></td>
        <td id="LC814" class="blob-code blob-code-inner js-file-line">	  SRlengthh=hcount;</td>
      </tr>
      <tr>
        <td id="L815" class="blob-num js-line-number" data-line-number="815"></td>
        <td id="LC815" class="blob-code blob-code-inner js-file-line">	  lengthbith=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthh/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L816" class="blob-num js-line-number" data-line-number="816"></td>
        <td id="LC816" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L817" class="blob-num js-line-number" data-line-number="817"></td>
        <td id="LC817" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L818" class="blob-num js-line-number" data-line-number="818"></td>
        <td id="LC818" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L819" class="blob-num js-line-number" data-line-number="819"></td>
        <td id="LC819" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][0])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][1])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][2])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L820" class="blob-num js-line-number" data-line-number="820"></td>
        <td id="LC820" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L821" class="blob-num js-line-number" data-line-number="821"></td>
        <td id="LC821" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L822" class="blob-num js-line-number" data-line-number="822"></td>
        <td id="LC822" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L823" class="blob-num js-line-number" data-line-number="823"></td>
        <td id="LC823" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L824" class="blob-num js-line-number" data-line-number="824"></td>
        <td id="LC824" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L825" class="blob-num js-line-number" data-line-number="825"></td>
        <td id="LC825" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L826" class="blob-num js-line-number" data-line-number="826"></td>
        <td id="LC826" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L827" class="blob-num js-line-number" data-line-number="827"></td>
        <td id="LC827" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L828" class="blob-num js-line-number" data-line-number="828"></td>
        <td id="LC828" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L829" class="blob-num js-line-number" data-line-number="829"></td>
        <td id="LC829" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L830" class="blob-num js-line-number" data-line-number="830"></td>
        <td id="LC830" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L831" class="blob-num js-line-number" data-line-number="831"></td>
        <td id="LC831" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L832" class="blob-num js-line-number" data-line-number="832"></td>
        <td id="LC832" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L833" class="blob-num js-line-number" data-line-number="833"></td>
        <td id="LC833" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L834" class="blob-num js-line-number" data-line-number="834"></td>
        <td id="LC834" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L835" class="blob-num js-line-number" data-line-number="835"></td>
        <td id="LC835" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">14</span>: <span class="pl-c"><span class="pl-c">//</span> was 36</span></td>
      </tr>
      <tr>
        <td id="L836" class="blob-num js-line-number" data-line-number="836"></td>
        <td id="LC836" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L837" class="blob-num js-line-number" data-line-number="837"></td>
        <td id="LC837" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> can use input bit as length of either SR = here is shift_regx</span></td>
      </tr>
      <tr>
        <td id="L838" class="blob-num js-line-number" data-line-number="838"></td>
        <td id="LC838" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> works ok not so interesting as 35</span></td>
      </tr>
      <tr>
        <td id="L839" class="blob-num js-line-number" data-line-number="839"></td>
        <td id="LC839" class="blob-code blob-code-inner js-file-line">       	hcount++;</td>
      </tr>
      <tr>
        <td id="L840" class="blob-num js-line-number" data-line-number="840"></td>
        <td id="LC840" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">31</span>) hcount=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L841" class="blob-num js-line-number" data-line-number="841"></td>
        <td id="LC841" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) {</td>
      </tr>
      <tr>
        <td id="L842" class="blob-num js-line-number" data-line-number="842"></td>
        <td id="LC842" class="blob-code blob-code-inner js-file-line">	  SRlengthx=hcount;</td>
      </tr>
      <tr>
        <td id="L843" class="blob-num js-line-number" data-line-number="843"></td>
        <td id="LC843" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L844" class="blob-num js-line-number" data-line-number="844"></td>
        <td id="LC844" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L845" class="blob-num js-line-number" data-line-number="845"></td>
        <td id="LC845" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L846" class="blob-num js-line-number" data-line-number="846"></td>
        <td id="LC846" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">0</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">1</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">2</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L847" class="blob-num js-line-number" data-line-number="847"></td>
        <td id="LC847" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerx &gt;&gt; 31) ^ (shift_registerx &gt;&gt; 29) ^ (shift_registerx &gt;&gt; 25) ^ (shift_registerx &gt;&gt; 24)) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L848" class="blob-num js-line-number" data-line-number="848"></td>
        <td id="LC848" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L849" class="blob-num js-line-number" data-line-number="849"></td>
        <td id="LC849" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L850" class="blob-num js-line-number" data-line-number="850"></td>
        <td id="LC850" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L851" class="blob-num js-line-number" data-line-number="851"></td>
        <td id="LC851" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L852" class="blob-num js-line-number" data-line-number="852"></td>
        <td id="LC852" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L853" class="blob-num js-line-number" data-line-number="853"></td>
        <td id="LC853" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L854" class="blob-num js-line-number" data-line-number="854"></td>
        <td id="LC854" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L855" class="blob-num js-line-number" data-line-number="855"></td>
        <td id="LC855" class="blob-code blob-code-inner js-file-line">	  </td>
      </tr>
      <tr>
        <td id="L856" class="blob-num js-line-number" data-line-number="856"></td>
        <td id="LC856" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L857" class="blob-num js-line-number" data-line-number="857"></td>
        <td id="LC857" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L858" class="blob-num js-line-number" data-line-number="858"></td>
        <td id="LC858" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L859" class="blob-num js-line-number" data-line-number="859"></td>
        <td id="LC859" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L860" class="blob-num js-line-number" data-line-number="860"></td>
        <td id="LC860" class="blob-code blob-code-inner js-file-line">	  }</td>
      </tr>
      <tr>
        <td id="L861" class="blob-num js-line-number" data-line-number="861"></td>
        <td id="LC861" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L862" class="blob-num js-line-number" data-line-number="862"></td>
        <td id="LC862" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L863" class="blob-num js-line-number" data-line-number="863"></td>
        <td id="LC863" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">15</span>: <span class="pl-c"><span class="pl-c">//</span> was 41</span></td>
      </tr>
      <tr>
        <td id="L864" class="blob-num js-line-number" data-line-number="864"></td>
        <td id="LC864" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> pulse in means double a step..</span></td>
      </tr>
      <tr>
        <td id="L865" class="blob-num js-line-number" data-line-number="865"></td>
        <td id="LC865" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L866" class="blob-num js-line-number" data-line-number="866"></td>
        <td id="LC866" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L867" class="blob-num js-line-number" data-line-number="867"></td>
        <td id="LC867" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L868" class="blob-num js-line-number" data-line-number="868"></td>
        <td id="LC868" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L869" class="blob-num js-line-number" data-line-number="869"></td>
        <td id="LC869" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0080</span>)) {</td>
      </tr>
      <tr>
        <td id="L870" class="blob-num js-line-number" data-line-number="870"></td>
        <td id="LC870" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L871" class="blob-num js-line-number" data-line-number="871"></td>
        <td id="LC871" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L872" class="blob-num js-line-number" data-line-number="872"></td>
        <td id="LC872" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L873" class="blob-num js-line-number" data-line-number="873"></td>
        <td id="LC873" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L874" class="blob-num js-line-number" data-line-number="874"></td>
        <td id="LC874" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L875" class="blob-num js-line-number" data-line-number="875"></td>
        <td id="LC875" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L876" class="blob-num js-line-number" data-line-number="876"></td>
        <td id="LC876" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L877" class="blob-num js-line-number" data-line-number="877"></td>
        <td id="LC877" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L878" class="blob-num js-line-number" data-line-number="878"></td>
        <td id="LC878" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; 	</td>
      </tr>
      <tr>
        <td id="L879" class="blob-num js-line-number" data-line-number="879"></td>
        <td id="LC879" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;	</td>
      </tr>
      <tr>
        <td id="L880" class="blob-num js-line-number" data-line-number="880"></td>
        <td id="LC880" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L881" class="blob-num js-line-number" data-line-number="881"></td>
        <td id="LC881" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> /END of HF SR side/..................................................................................................................    </span></td>
      </tr>
      <tr>
        <td id="L882" class="blob-num js-line-number" data-line-number="882"></td>
        <td id="LC882" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L883" class="blob-num js-line-number" data-line-number="883"></td>
        <td id="LC883" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L884" class="blob-num js-line-number" data-line-number="884"></td>
        <td id="LC884" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L885" class="blob-num js-line-number" data-line-number="885"></td>
        <td id="LC885" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">TIM4_IRQHandler</span>(<span class="pl-k">void</span>){</td>
      </tr>
      <tr>
        <td id="L886" class="blob-num js-line-number" data-line-number="886"></td>
        <td id="LC886" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> select modes, speeds and if necessary handle PWM depending on mode. Speed from main.c is 1KHz</span></td>
      </tr>
      <tr>
        <td id="L887" class="blob-num js-line-number" data-line-number="887"></td>
        <td id="LC887" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">TIM_ClearITPendingBit</span>(TIM4, TIM_IT_Update);</td>
      </tr>
      <tr>
        <td id="L888" class="blob-num js-line-number" data-line-number="888"></td>
        <td id="LC888" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L889" class="blob-num js-line-number" data-line-number="889"></td>
        <td id="LC889" class="blob-code blob-code-inner js-file-line">  model=ADCBuffer[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L890" class="blob-num js-line-number" data-line-number="890"></td>
        <td id="LC890" class="blob-code blob-code-inner js-file-line">  modeh=ADCBuffer[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L891" class="blob-num js-line-number" data-line-number="891"></td>
        <td id="LC891" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L892" class="blob-num js-line-number" data-line-number="892"></td>
        <td id="LC892" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> so we have 32 modes for hpwm and 2 modes for pwm - do we need smoothings -&gt;</span></td>
      </tr>
      <tr>
        <td id="L893" class="blob-num js-line-number" data-line-number="893"></td>
        <td id="LC893" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> tested with blank and no smoothing is necessary  </span></td>
      </tr>
      <tr>
        <td id="L894" class="blob-num js-line-number" data-line-number="894"></td>
        <td id="LC894" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L895" class="blob-num js-line-number" data-line-number="895"></td>
        <td id="LC895" class="blob-code blob-code-inner js-file-line">  modehpwm=modeh&gt;&gt;<span class="pl-c1">15</span>; <span class="pl-c"><span class="pl-c">//</span> 1 bits remaining</span></td>
      </tr>
      <tr>
        <td id="L896" class="blob-num js-line-number" data-line-number="896"></td>
        <td id="LC896" class="blob-code blob-code-inner js-file-line">  modehsr=<span class="pl-c1">31</span>-(modeh&gt;&gt;<span class="pl-c1">10</span>)%<span class="pl-c1">32</span>; <span class="pl-c"><span class="pl-c">//</span> 32 modes</span></td>
      </tr>
      <tr>
        <td id="L897" class="blob-num js-line-number" data-line-number="897"></td>
        <td id="LC897" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L898" class="blob-num js-line-number" data-line-number="898"></td>
        <td id="LC898" class="blob-code blob-code-inner js-file-line">  speedh=logger[ADCBuffer[<span class="pl-c1">2</span>]&gt;&gt;<span class="pl-c1">6</span>]; <span class="pl-c"><span class="pl-c">//</span> 1024  = 10 bits -&gt; could be less logger to make smoother?</span></td>
      </tr>
      <tr>
        <td id="L899" class="blob-num js-line-number" data-line-number="899"></td>
        <td id="LC899" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">if</span> (modehpwm==<span class="pl-c1">0</span>) {     <span class="pl-c"><span class="pl-c">//</span> invert the speedhh;</span></td>
      </tr>
      <tr>
        <td id="L900" class="blob-num js-line-number" data-line-number="900"></td>
        <td id="LC900" class="blob-code blob-code-inner js-file-line">    speedhh=logforSR[<span class="pl-c1">1024</span>-(ADCBuffer[<span class="pl-c1">2</span>]&gt;&gt;<span class="pl-c1">6</span>)]; <span class="pl-c"><span class="pl-c">//</span> or recalculate from log? TESTY!</span></td>
      </tr>
      <tr>
        <td id="L901" class="blob-num js-line-number" data-line-number="901"></td>
        <td id="LC901" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L902" class="blob-num js-line-number" data-line-number="902"></td>
        <td id="LC902" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">else</span>  speedhh=logforSR[ADCBuffer[<span class="pl-c1">2</span>]&gt;&gt;<span class="pl-c1">6</span>]; <span class="pl-c"><span class="pl-c">//</span> 1024 option = 10 bits log -&gt;  could be less logger to make smoother? - could also be a lot slower at one end</span></td>
      </tr>
      <tr>
        <td id="L903" class="blob-num js-line-number" data-line-number="903"></td>
        <td id="LC903" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L904" class="blob-num js-line-number" data-line-number="904"></td>
        <td id="LC904" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span>  modelpwm=1; // TESTY! </span></td>
      </tr>
      <tr>
        <td id="L905" class="blob-num js-line-number" data-line-number="905"></td>
        <td id="LC905" class="blob-code blob-code-inner js-file-line">  modelpwm=model&gt;&gt;<span class="pl-c1">15</span>; <span class="pl-c"><span class="pl-c">//</span> 1 bits remaining</span></td>
      </tr>
      <tr>
        <td id="L906" class="blob-num js-line-number" data-line-number="906"></td>
        <td id="LC906" class="blob-code blob-code-inner js-file-line">  modelsr=<span class="pl-c1">31</span>-(model&gt;&gt;<span class="pl-c1">10</span>)%<span class="pl-c1">32</span>; <span class="pl-c"><span class="pl-c">//</span> 32 modes</span></td>
      </tr>
      <tr>
        <td id="L907" class="blob-num js-line-number" data-line-number="907"></td>
        <td id="LC907" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L908" class="blob-num js-line-number" data-line-number="908"></td>
        <td id="LC908" class="blob-code blob-code-inner js-file-line">  speedl=logger[ADCBuffer[<span class="pl-c1">3</span>]&gt;&gt;<span class="pl-c1">6</span>]; <span class="pl-c"><span class="pl-c">//</span> 1024  = 10 bits -&gt; could be less logger to make smoother?</span></td>
      </tr>
      <tr>
        <td id="L909" class="blob-num js-line-number" data-line-number="909"></td>
        <td id="LC909" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">if</span> (modelpwm==<span class="pl-c1">0</span>) {     <span class="pl-c"><span class="pl-c">//</span> invert the speedhh;</span></td>
      </tr>
      <tr>
        <td id="L910" class="blob-num js-line-number" data-line-number="910"></td>
        <td id="LC910" class="blob-code blob-code-inner js-file-line">    speedll=logforSR[<span class="pl-c1">1024</span>-(ADCBuffer[<span class="pl-c1">3</span>]&gt;&gt;<span class="pl-c1">6</span>)]; <span class="pl-c"><span class="pl-c">//</span> or recalculate from log? TESTY!</span></td>
      </tr>
      <tr>
        <td id="L911" class="blob-num js-line-number" data-line-number="911"></td>
        <td id="LC911" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L912" class="blob-num js-line-number" data-line-number="912"></td>
        <td id="LC912" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">else</span>  speedll=logforSR[ADCBuffer[<span class="pl-c1">3</span>]&gt;&gt;<span class="pl-c1">6</span>]; <span class="pl-c"><span class="pl-c">//</span> 1024 option = 10 bits log -&gt;  could be less logger to make smoother? - could also be a lot slower at one end</span></td>
      </tr>
      <tr>
        <td id="L913" class="blob-num js-line-number" data-line-number="913"></td>
        <td id="LC913" class="blob-code blob-code-inner js-file-line">  </td>
      </tr>
      <tr>
        <td id="L914" class="blob-num js-line-number" data-line-number="914"></td>
        <td id="LC914" class="blob-code blob-code-inner js-file-line">  TIM1-&gt;<span class="pl-smi">ARR</span> = speedh;<span class="pl-c"><span class="pl-c">//</span>period</span></td>
      </tr>
      <tr>
        <td id="L915" class="blob-num js-line-number" data-line-number="915"></td>
        <td id="LC915" class="blob-code blob-code-inner js-file-line">  TIM1-&gt;<span class="pl-smi">CCR1</span> = speedh/<span class="pl-c1">2</span>; <span class="pl-c"><span class="pl-c">//</span> pulse  </span></td>
      </tr>
      <tr>
        <td id="L916" class="blob-num js-line-number" data-line-number="916"></td>
        <td id="LC916" class="blob-code blob-code-inner js-file-line">  TIM3-&gt;<span class="pl-smi">ARR</span> = speedl;<span class="pl-c"><span class="pl-c">//</span>period</span></td>
      </tr>
      <tr>
        <td id="L917" class="blob-num js-line-number" data-line-number="917"></td>
        <td id="LC917" class="blob-code blob-code-inner js-file-line">  TIM3-&gt;<span class="pl-smi">CCR1</span> = speedl/<span class="pl-c1">2</span>; <span class="pl-c"><span class="pl-c">//</span> pulse  </span></td>
      </tr>
      <tr>
        <td id="L918" class="blob-num js-line-number" data-line-number="918"></td>
        <td id="LC918" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L919" class="blob-num js-line-number" data-line-number="919"></td>
        <td id="LC919" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L920" class="blob-num js-line-number" data-line-number="920"></td>
        <td id="LC920" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L921" class="blob-num js-line-number" data-line-number="921"></td>
        <td id="LC921" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">EXTI9_5_IRQHandler</span>(<span class="pl-k">void</span>){</td>
      </tr>
      <tr>
        <td id="L922" class="blob-num js-line-number" data-line-number="922"></td>
        <td id="LC922" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> LF and HF pulse in on falling edges</span></td>
      </tr>
      <tr>
        <td id="L923" class="blob-num js-line-number" data-line-number="923"></td>
        <td id="LC923" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L924" class="blob-num js-line-number" data-line-number="924"></td>
        <td id="LC924" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint8_t</span> x, numflips, shifter;</td>
      </tr>
      <tr>
        <td id="L925" class="blob-num js-line-number" data-line-number="925"></td>
        <td id="LC925" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint8_t</span> bith, bitl;</td>
      </tr>
      <tr>
        <td id="L926" class="blob-num js-line-number" data-line-number="926"></td>
        <td id="LC926" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint32_t</span> pending = EXTI-&gt;<span class="pl-smi">PR</span>, cvalue, clvalue;</td>
      </tr>
      <tr>
        <td id="L927" class="blob-num js-line-number" data-line-number="927"></td>
        <td id="LC927" class="blob-code blob-code-inner js-file-line">  <span class="pl-c1">uint32_t</span> SRlengthx=<span class="pl-c1">31</span>;</td>
      </tr>
      <tr>
        <td id="L928" class="blob-num js-line-number" data-line-number="928"></td>
        <td id="LC928" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L929" class="blob-num js-line-number" data-line-number="929"></td>
        <td id="LC929" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> --------------------LF pulse modes</span></td>
      </tr>
      <tr>
        <td id="L930" class="blob-num js-line-number" data-line-number="930"></td>
        <td id="LC930" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">if</span>(pending &amp; (<span class="pl-c1">1</span> &lt;&lt; <span class="pl-c1">5</span>)) { <span class="pl-c"><span class="pl-c">//</span> LF on 5 out on B</span></td>
      </tr>
      <tr>
        <td id="L931" class="blob-num js-line-number" data-line-number="931"></td>
        <td id="LC931" class="blob-code blob-code-inner js-file-line">    EXTI-&gt;<span class="pl-smi">PR</span> = <span class="pl-c1">1</span> &lt;&lt; <span class="pl-c1">5</span>; <span class="pl-c"><span class="pl-c">//</span> clear pending flag, otherwise we&#39;d get endless interrupts -!!!!!!!!!!!!!!!!!!!!!!!!!        // handle pin 5 here</span></td>
      </tr>
      <tr>
        <td id="L932" class="blob-num js-line-number" data-line-number="932"></td>
        <td id="LC932" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L933" class="blob-num js-line-number" data-line-number="933"></td>
        <td id="LC933" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span> (modelpwm==<span class="pl-c1">0</span>) clvalue=<span class="pl-c1">65536</span>-ADCBuffer[<span class="pl-c1">3</span>];  </td>
      </tr>
      <tr>
        <td id="L934" class="blob-num js-line-number" data-line-number="934"></td>
        <td id="LC934" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">else</span> clvalue=ADCBuffer[<span class="pl-c1">3</span>];</td>
      </tr>
      <tr>
        <td id="L935" class="blob-num js-line-number" data-line-number="935"></td>
        <td id="LC935" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L936" class="blob-num js-line-number" data-line-number="936"></td>
        <td id="LC936" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span> ported from HF and tested</span></td>
      </tr>
      <tr>
        <td id="L937" class="blob-num js-line-number" data-line-number="937"></td>
        <td id="LC937" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">switch</span>(modelsr){</td>
      </tr>
      <tr>
        <td id="L938" class="blob-num js-line-number" data-line-number="938"></td>
        <td id="LC938" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">16</span>: <span class="pl-c"><span class="pl-c">//</span> was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO</span></td>
      </tr>
      <tr>
        <td id="L939" class="blob-num js-line-number" data-line-number="939"></td>
        <td id="LC939" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; CV selects length of SR which will stay with us .. -&gt; LFSR here</span></td>
      </tr>
      <tr>
        <td id="L940" class="blob-num js-line-number" data-line-number="940"></td>
        <td id="LC940" class="blob-code blob-code-inner js-file-line">      SRlengthl=<span class="pl-c1">31</span>-(clvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L941" class="blob-num js-line-number" data-line-number="941"></td>
        <td id="LC941" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthl&lt;<span class="pl-c1">4</span>) SRlengthl=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L942" class="blob-num js-line-number" data-line-number="942"></td>
        <td id="LC942" class="blob-code blob-code-inner js-file-line">      lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthl/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L943" class="blob-num js-line-number" data-line-number="943"></td>
        <td id="LC943" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl==<span class="pl-c1">0</span>) shift_registerl=<span class="pl-c1">0xff</span>;</td>
      </tr>
      <tr>
        <td id="L944" class="blob-num js-line-number" data-line-number="944"></td>
        <td id="LC944" class="blob-code blob-code-inner js-file-line">      bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">0</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">1</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">2</span>])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L945" class="blob-num js-line-number" data-line-number="945"></td>
        <td id="LC945" class="blob-code blob-code-inner js-file-line">      shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((bitl | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>))); <span class="pl-c"><span class="pl-c">//</span> PB7 and PB10</span></td>
      </tr>
      <tr>
        <td id="L946" class="blob-num js-line-number" data-line-number="946"></td>
        <td id="LC946" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L947" class="blob-num js-line-number" data-line-number="947"></td>
        <td id="LC947" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L948" class="blob-num js-line-number" data-line-number="948"></td>
        <td id="LC948" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L949" class="blob-num js-line-number" data-line-number="949"></td>
        <td id="LC949" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L950" class="blob-num js-line-number" data-line-number="950"></td>
        <td id="LC950" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L951" class="blob-num js-line-number" data-line-number="951"></td>
        <td id="LC951" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L952" class="blob-num js-line-number" data-line-number="952"></td>
        <td id="LC952" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L953" class="blob-num js-line-number" data-line-number="953"></td>
        <td id="LC953" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">17</span>: <span class="pl-c"><span class="pl-c">//</span> was 10</span></td>
      </tr>
      <tr>
        <td id="L954" class="blob-num js-line-number" data-line-number="954"></td>
        <td id="LC954" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit </span></td>
      </tr>
      <tr>
        <td id="L955" class="blob-num js-line-number" data-line-number="955"></td>
        <td id="LC955" class="blob-code blob-code-inner js-file-line">      lcount++;</td>
      </tr>
      <tr>
        <td id="L956" class="blob-num js-line-number" data-line-number="956"></td>
        <td id="LC956" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">7</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L957" class="blob-num js-line-number" data-line-number="957"></td>
        <td id="LC957" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L958" class="blob-num js-line-number" data-line-number="958"></td>
        <td id="LC958" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L959" class="blob-num js-line-number" data-line-number="959"></td>
        <td id="LC959" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span>((clvalue&gt;&gt;(<span class="pl-c1">8</span>+lcount))&amp;<span class="pl-c1">1</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L960" class="blob-num js-line-number" data-line-number="960"></td>
        <td id="LC960" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L961" class="blob-num js-line-number" data-line-number="961"></td>
        <td id="LC961" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L962" class="blob-num js-line-number" data-line-number="962"></td>
        <td id="LC962" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L963" class="blob-num js-line-number" data-line-number="963"></td>
        <td id="LC963" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L964" class="blob-num js-line-number" data-line-number="964"></td>
        <td id="LC964" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L965" class="blob-num js-line-number" data-line-number="965"></td>
        <td id="LC965" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L966" class="blob-num js-line-number" data-line-number="966"></td>
        <td id="LC966" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L967" class="blob-num js-line-number" data-line-number="967"></td>
        <td id="LC967" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L968" class="blob-num js-line-number" data-line-number="968"></td>
        <td id="LC968" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">18</span>: <span class="pl-c"><span class="pl-c">//</span> was 12 - works fine with cv in</span></td>
      </tr>
      <tr>
        <td id="L969" class="blob-num js-line-number" data-line-number="969"></td>
        <td id="LC969" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; NEW mode TESTY: entry of ADC in from CV into upper bits?</span></td>
      </tr>
      <tr>
        <td id="L970" class="blob-num js-line-number" data-line-number="970"></td>
        <td id="LC970" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L971" class="blob-num js-line-number" data-line-number="971"></td>
        <td id="LC971" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L972" class="blob-num js-line-number" data-line-number="972"></td>
        <td id="LC972" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (counter12l == <span class="pl-c1">9</span>){       <span class="pl-c"><span class="pl-c">//</span> every 8 cycles</span></td>
      </tr>
      <tr>
        <td id="L973" class="blob-num js-line-number" data-line-number="973"></td>
        <td id="LC973" class="blob-code blob-code-inner js-file-line">	counter12l=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L974" class="blob-num js-line-number" data-line-number="974"></td>
        <td id="LC974" class="blob-code blob-code-inner js-file-line">	shift_registerl &amp;= MASK[SRlengthl]; <span class="pl-c"><span class="pl-c">//</span> MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths</span></td>
      </tr>
      <tr>
        <td id="L975" class="blob-num js-line-number" data-line-number="975"></td>
        <td id="LC975" class="blob-code blob-code-inner js-file-line">	shift_registerl +=(clvalue&gt;&gt;<span class="pl-c1">8</span>)&lt;&lt;(SHIFT[SRlengthl]); </td>
      </tr>
      <tr>
        <td id="L976" class="blob-num js-line-number" data-line-number="976"></td>
        <td id="LC976" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L977" class="blob-num js-line-number" data-line-number="977"></td>
        <td id="LC977" class="blob-code blob-code-inner js-file-line">      counter12l++;</td>
      </tr>
      <tr>
        <td id="L978" class="blob-num js-line-number" data-line-number="978"></td>
        <td id="LC978" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L979" class="blob-num js-line-number" data-line-number="979"></td>
        <td id="LC979" class="blob-code blob-code-inner js-file-line">      shift_registerl=(shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (bitl |  (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>))); <span class="pl-c"><span class="pl-c">//</span> cycle around and OR in pulse bit! TESTY!</span></td>
      </tr>
      <tr>
        <td id="L980" class="blob-num js-line-number" data-line-number="980"></td>
        <td id="LC980" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L981" class="blob-num js-line-number" data-line-number="981"></td>
        <td id="LC981" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L982" class="blob-num js-line-number" data-line-number="982"></td>
        <td id="LC982" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L983" class="blob-num js-line-number" data-line-number="983"></td>
        <td id="LC983" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L984" class="blob-num js-line-number" data-line-number="984"></td>
        <td id="LC984" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L985" class="blob-num js-line-number" data-line-number="985"></td>
        <td id="LC985" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L986" class="blob-num js-line-number" data-line-number="986"></td>
        <td id="LC986" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L987" class="blob-num js-line-number" data-line-number="987"></td>
        <td id="LC987" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">19</span>: <span class="pl-c"><span class="pl-c">//</span> was 13</span></td>
      </tr>
      <tr>
        <td id="L988" class="blob-num js-line-number" data-line-number="988"></td>
        <td id="LC988" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L989" class="blob-num js-line-number" data-line-number="989"></td>
        <td id="LC989" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> we do not use bit IN!</span></td>
      </tr>
      <tr>
        <td id="L990" class="blob-num js-line-number" data-line-number="990"></td>
        <td id="LC990" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L991" class="blob-num js-line-number" data-line-number="991"></td>
        <td id="LC991" class="blob-code blob-code-inner js-file-line">      probl=clvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L992" class="blob-num js-line-number" data-line-number="992"></td>
        <td id="LC992" class="blob-code blob-code-inner js-file-line">      probl=electroprob[probl];</td>
      </tr>
      <tr>
        <td id="L993" class="blob-num js-line-number" data-line-number="993"></td>
        <td id="LC993" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L994" class="blob-num js-line-number" data-line-number="994"></td>
        <td id="LC994" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probl | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> new bits enter from shiftregleft - 0xff was looker[7]</span></td>
      </tr>
      <tr>
        <td id="L995" class="blob-num js-line-number" data-line-number="995"></td>
        <td id="LC995" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L996" class="blob-num js-line-number" data-line-number="996"></td>
        <td id="LC996" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L997" class="blob-num js-line-number" data-line-number="997"></td>
        <td id="LC997" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L998" class="blob-num js-line-number" data-line-number="998"></td>
        <td id="LC998" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L999" class="blob-num js-line-number" data-line-number="999"></td>
        <td id="LC999" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1000" class="blob-num js-line-number" data-line-number="1000"></td>
        <td id="LC1000" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1001" class="blob-num js-line-number" data-line-number="1001"></td>
        <td id="LC1001" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1002" class="blob-num js-line-number" data-line-number="1002"></td>
        <td id="LC1002" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1003" class="blob-num js-line-number" data-line-number="1003"></td>
        <td id="LC1003" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">20</span>: <span class="pl-c"><span class="pl-c">//</span> was 14 - could replace mode or one of these ???</span></td>
      </tr>
      <tr>
        <td id="L1004" class="blob-num js-line-number" data-line-number="1004"></td>
        <td id="LC1004" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; uses CV as speed/flipflop/clock divider</span></td>
      </tr>
      <tr>
        <td id="L1005" class="blob-num js-line-number" data-line-number="1005"></td>
        <td id="LC1005" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit</span></td>
      </tr>
      <tr>
        <td id="L1006" class="blob-num js-line-number" data-line-number="1006"></td>
        <td id="LC1006" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1007" class="blob-num js-line-number" data-line-number="1007"></td>
        <td id="LC1007" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      origbitl=bitl;</span></td>
      </tr>
      <tr>
        <td id="L1008" class="blob-num js-line-number" data-line-number="1008"></td>
        <td id="LC1008" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl =  (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1009" class="blob-num js-line-number" data-line-number="1009"></td>
        <td id="LC1009" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L1010" class="blob-num js-line-number" data-line-number="1010"></td>
        <td id="LC1010" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1011" class="blob-num js-line-number" data-line-number="1011"></td>
        <td id="LC1011" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1</span></td>
      </tr>
      <tr>
        <td id="L1012" class="blob-num js-line-number" data-line-number="1012"></td>
        <td id="LC1012" class="blob-code blob-code-inner js-file-line">      numflips=(clvalue&gt;&gt;<span class="pl-c1">12</span>); <span class="pl-c"><span class="pl-c">//</span>or 15-(clvalue&gt;&gt;12) if we wish it to go in the opposite direction</span></td>
      </tr>
      <tr>
        <td id="L1013" class="blob-num js-line-number" data-line-number="1013"></td>
        <td id="LC1013" class="blob-code blob-code-inner js-file-line">      new_statel[<span class="pl-c1">0</span>]=bitl;</td>
      </tr>
      <tr>
        <td id="L1014" class="blob-num js-line-number" data-line-number="1014"></td>
        <td id="LC1014" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (prev_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">0</span> &amp;&amp; new_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">1</span>) flippedl[<span class="pl-c1">0</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1015" class="blob-num js-line-number" data-line-number="1015"></td>
        <td id="LC1015" class="blob-code blob-code-inner js-file-line">      prev_statel[<span class="pl-c1">0</span>]=new_statel[<span class="pl-c1">0</span>];	</td>
      </tr>
      <tr>
        <td id="L1016" class="blob-num js-line-number" data-line-number="1016"></td>
        <td id="LC1016" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1017" class="blob-num js-line-number" data-line-number="1017"></td>
        <td id="LC1017" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">1</span>;x&lt;numflips;x++){ </td>
      </tr>
      <tr>
        <td id="L1018" class="blob-num js-line-number" data-line-number="1018"></td>
        <td id="LC1018" class="blob-code blob-code-inner js-file-line">	new_statel[x]=flippedl[x-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1019" class="blob-num js-line-number" data-line-number="1019"></td>
        <td id="LC1019" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_statel[x]==<span class="pl-c1">0</span> &amp;&amp; new_statel[x]==<span class="pl-c1">1</span>) flippedl[x]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1020" class="blob-num js-line-number" data-line-number="1020"></td>
        <td id="LC1020" class="blob-code blob-code-inner js-file-line">	prev_statel[x]=new_statel[x];</td>
      </tr>
      <tr>
        <td id="L1021" class="blob-num js-line-number" data-line-number="1021"></td>
        <td id="LC1021" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1022" class="blob-num js-line-number" data-line-number="1022"></td>
        <td id="LC1022" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (numflips&gt;<span class="pl-c1">0</span>)	bitl=flippedl[numflips-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1023" class="blob-num js-line-number" data-line-number="1023"></td>
        <td id="LC1023" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1024" class="blob-num js-line-number" data-line-number="1024"></td>
        <td id="LC1024" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1025" class="blob-num js-line-number" data-line-number="1025"></td>
        <td id="LC1025" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1026" class="blob-num js-line-number" data-line-number="1026"></td>
        <td id="LC1026" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      if (origbitl) GPIOB-&gt;BRR = 0b0100000000000000;  // original bitl </span></td>
      </tr>
      <tr>
        <td id="L1027" class="blob-num js-line-number" data-line-number="1027"></td>
        <td id="LC1027" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      else GPIOB-&gt;BSRR = 0b0100000000000000;</span></td>
      </tr>
      <tr>
        <td id="L1028" class="blob-num js-line-number" data-line-number="1028"></td>
        <td id="LC1028" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) {</td>
      </tr>
      <tr>
        <td id="L1029" class="blob-num js-line-number" data-line-number="1029"></td>
        <td id="LC1029" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl)	GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1030" class="blob-num js-line-number" data-line-number="1030"></td>
        <td id="LC1030" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1031" class="blob-num js-line-number" data-line-number="1031"></td>
        <td id="LC1031" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1032" class="blob-num js-line-number" data-line-number="1032"></td>
        <td id="LC1032" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1033" class="blob-num js-line-number" data-line-number="1033"></td>
        <td id="LC1033" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1034" class="blob-num js-line-number" data-line-number="1034"></td>
        <td id="LC1034" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">21</span>: <span class="pl-c"><span class="pl-c">//</span> was 15</span></td>
      </tr>
      <tr>
        <td id="L1035" class="blob-num js-line-number" data-line-number="1035"></td>
        <td id="LC1035" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; as mode 14=speed divider with XOR rungler: XOR out with input bit</span></td>
      </tr>
      <tr>
        <td id="L1036" class="blob-num js-line-number" data-line-number="1036"></td>
        <td id="LC1036" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1037" class="blob-num js-line-number" data-line-number="1037"></td>
        <td id="LC1037" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      origbitl=bitl;</span></td>
      </tr>
      <tr>
        <td id="L1038" class="blob-num js-line-number" data-line-number="1038"></td>
        <td id="LC1038" class="blob-code blob-code-inner js-file-line">      shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((bitl) ^ (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)));</td>
      </tr>
      <tr>
        <td id="L1039" class="blob-num js-line-number" data-line-number="1039"></td>
        <td id="LC1039" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1040" class="blob-num js-line-number" data-line-number="1040"></td>
        <td id="LC1040" class="blob-code blob-code-inner js-file-line">      numflips=(clvalue&gt;&gt;<span class="pl-c1">12</span>); <span class="pl-c"><span class="pl-c">//</span>or 15-(clvalue&gt;&gt;12) if we wish it to go in the opposite direction</span></td>
      </tr>
      <tr>
        <td id="L1041" class="blob-num js-line-number" data-line-number="1041"></td>
        <td id="LC1041" class="blob-code blob-code-inner js-file-line">      new_statel[<span class="pl-c1">0</span>]=bitl;</td>
      </tr>
      <tr>
        <td id="L1042" class="blob-num js-line-number" data-line-number="1042"></td>
        <td id="LC1042" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (prev_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">0</span> &amp;&amp; new_statel[<span class="pl-c1">0</span>]==<span class="pl-c1">1</span>) flippedl[<span class="pl-c1">0</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1043" class="blob-num js-line-number" data-line-number="1043"></td>
        <td id="LC1043" class="blob-code blob-code-inner js-file-line">      prev_statel[<span class="pl-c1">0</span>]=new_statel[<span class="pl-c1">0</span>];	</td>
      </tr>
      <tr>
        <td id="L1044" class="blob-num js-line-number" data-line-number="1044"></td>
        <td id="LC1044" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1045" class="blob-num js-line-number" data-line-number="1045"></td>
        <td id="LC1045" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">1</span>;x&lt;numflips;x++){ </td>
      </tr>
      <tr>
        <td id="L1046" class="blob-num js-line-number" data-line-number="1046"></td>
        <td id="LC1046" class="blob-code blob-code-inner js-file-line">	new_statel[x]=flippedl[x-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1047" class="blob-num js-line-number" data-line-number="1047"></td>
        <td id="LC1047" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_statel[x]==<span class="pl-c1">0</span> &amp;&amp; new_statel[x]==<span class="pl-c1">1</span>) flippedl[x]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1048" class="blob-num js-line-number" data-line-number="1048"></td>
        <td id="LC1048" class="blob-code blob-code-inner js-file-line">	prev_statel[x]=new_statel[x];</td>
      </tr>
      <tr>
        <td id="L1049" class="blob-num js-line-number" data-line-number="1049"></td>
        <td id="LC1049" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1050" class="blob-num js-line-number" data-line-number="1050"></td>
        <td id="LC1050" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (numflips&gt;<span class="pl-c1">0</span>)	bitl=flippedl[numflips-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1051" class="blob-num js-line-number" data-line-number="1051"></td>
        <td id="LC1051" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1052" class="blob-num js-line-number" data-line-number="1052"></td>
        <td id="LC1052" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1053" class="blob-num js-line-number" data-line-number="1053"></td>
        <td id="LC1053" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1054" class="blob-num js-line-number" data-line-number="1054"></td>
        <td id="LC1054" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) {</td>
      </tr>
      <tr>
        <td id="L1055" class="blob-num js-line-number" data-line-number="1055"></td>
        <td id="LC1055" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl)	GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1056" class="blob-num js-line-number" data-line-number="1056"></td>
        <td id="LC1056" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1057" class="blob-num js-line-number" data-line-number="1057"></td>
        <td id="LC1057" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1058" class="blob-num js-line-number" data-line-number="1058"></td>
        <td id="LC1058" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      if (origbitl) GPIOB-&gt;BRR = 0b0100000000000000;  // original bitl </span></td>
      </tr>
      <tr>
        <td id="L1059" class="blob-num js-line-number" data-line-number="1059"></td>
        <td id="LC1059" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      else GPIOB-&gt;BSRR = 0b0100000000000000;</span></td>
      </tr>
      <tr>
        <td id="L1060" class="blob-num js-line-number" data-line-number="1060"></td>
        <td id="LC1060" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1061" class="blob-num js-line-number" data-line-number="1061"></td>
        <td id="LC1061" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1062" class="blob-num js-line-number" data-line-number="1062"></td>
        <td id="LC1062" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">22</span>: <span class="pl-c"><span class="pl-c">//</span> was 43</span></td>
      </tr>
      <tr>
        <td id="L1063" class="blob-num js-line-number" data-line-number="1063"></td>
        <td id="LC1063" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as above but other way round with CV for length and incoming bits for probability of TM</span></td>
      </tr>
      <tr>
        <td id="L1064" class="blob-num js-line-number" data-line-number="1064"></td>
        <td id="LC1064" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1065" class="blob-num js-line-number" data-line-number="1065"></td>
        <td id="LC1065" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1066" class="blob-num js-line-number" data-line-number="1066"></td>
        <td id="LC1066" class="blob-code blob-code-inner js-file-line">      SRlengthl=<span class="pl-c1">31</span>-(clvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1067" class="blob-num js-line-number" data-line-number="1067"></td>
        <td id="LC1067" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthl&lt;<span class="pl-c1">4</span>) SRlengthl=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1068" class="blob-num js-line-number" data-line-number="1068"></td>
        <td id="LC1068" class="blob-code blob-code-inner js-file-line">      lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthl/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L1069" class="blob-num js-line-number" data-line-number="1069"></td>
        <td id="LC1069" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1070" class="blob-num js-line-number" data-line-number="1070"></td>
        <td id="LC1070" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">7</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1071" class="blob-num js-line-number" data-line-number="1071"></td>
        <td id="LC1071" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)) probl^=(<span class="pl-c1">1</span>&lt;&lt;lcount);</td>
      </tr>
      <tr>
        <td id="L1072" class="blob-num js-line-number" data-line-number="1072"></td>
        <td id="LC1072" class="blob-code blob-code-inner js-file-line">      lcount++;</td>
      </tr>
      <tr>
        <td id="L1073" class="blob-num js-line-number" data-line-number="1073"></td>
        <td id="LC1073" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1074" class="blob-num js-line-number" data-line-number="1074"></td>
        <td id="LC1074" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probl | shift_registerh) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1075" class="blob-num js-line-number" data-line-number="1075"></td>
        <td id="LC1075" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L1076" class="blob-num js-line-number" data-line-number="1076"></td>
        <td id="LC1076" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1077" class="blob-num js-line-number" data-line-number="1077"></td>
        <td id="LC1077" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1078" class="blob-num js-line-number" data-line-number="1078"></td>
        <td id="LC1078" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1079" class="blob-num js-line-number" data-line-number="1079"></td>
        <td id="LC1079" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1080" class="blob-num js-line-number" data-line-number="1080"></td>
        <td id="LC1080" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1081" class="blob-num js-line-number" data-line-number="1081"></td>
        <td id="LC1081" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1082" class="blob-num js-line-number" data-line-number="1082"></td>
        <td id="LC1082" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1083" class="blob-num js-line-number" data-line-number="1083"></td>
        <td id="LC1083" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">23</span>: <span class="pl-c"><span class="pl-c">//</span> was 44</span></td>
      </tr>
      <tr>
        <td id="L1084" class="blob-num js-line-number" data-line-number="1084"></td>
        <td id="LC1084" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as mode 10 </span></td>
      </tr>
      <tr>
        <td id="L1085" class="blob-num js-line-number" data-line-number="1085"></td>
        <td id="LC1085" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*</span></td>
      </tr>
      <tr>
        <td id="L1086" class="blob-num js-line-number" data-line-number="1086"></td>
        <td id="LC1086" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1087" class="blob-num js-line-number" data-line-number="1087"></td>
        <td id="LC1087" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)){</td>
      </tr>
      <tr>
        <td id="L1088" class="blob-num js-line-number" data-line-number="1088"></td>
        <td id="LC1088" class="blob-code blob-code-inner js-file-line">	lcount++;</td>
      </tr>
      <tr>
        <td id="L1089" class="blob-num js-line-number" data-line-number="1089"></td>
        <td id="LC1089" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">7</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1090" class="blob-num js-line-number" data-line-number="1090"></td>
        <td id="LC1090" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1091" class="blob-num js-line-number" data-line-number="1091"></td>
        <td id="LC1091" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>((clvalue&gt;&gt;(<span class="pl-c1">8</span>+lcount))&amp;<span class="pl-c1">1</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L1092" class="blob-num js-line-number" data-line-number="1092"></td>
        <td id="LC1092" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1093" class="blob-num js-line-number" data-line-number="1093"></td>
        <td id="LC1093" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1094" class="blob-num js-line-number" data-line-number="1094"></td>
        <td id="LC1094" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1095" class="blob-num js-line-number" data-line-number="1095"></td>
        <td id="LC1095" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1096" class="blob-num js-line-number" data-line-number="1096"></td>
        <td id="LC1096" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1097" class="blob-num js-line-number" data-line-number="1097"></td>
        <td id="LC1097" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1098" class="blob-num js-line-number" data-line-number="1098"></td>
        <td id="LC1098" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1099" class="blob-num js-line-number" data-line-number="1099"></td>
        <td id="LC1099" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1100" class="blob-num js-line-number" data-line-number="1100"></td>
        <td id="LC1100" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1101" class="blob-num js-line-number" data-line-number="1101"></td>
        <td id="LC1101" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">24</span>: <span class="pl-c"><span class="pl-c">//</span> was 45</span></td>
      </tr>
      <tr>
        <td id="L1102" class="blob-num js-line-number" data-line-number="1102"></td>
        <td id="LC1102" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit = 3rd option of above...</span></td>
      </tr>
      <tr>
        <td id="L1103" class="blob-num js-line-number" data-line-number="1103"></td>
        <td id="LC1103" class="blob-code blob-code-inner js-file-line">      	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1104" class="blob-num js-line-number" data-line-number="1104"></td>
        <td id="LC1104" class="blob-code blob-code-inner js-file-line">      lcount++;</td>
      </tr>
      <tr>
        <td id="L1105" class="blob-num js-line-number" data-line-number="1105"></td>
        <td id="LC1105" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (lcount&gt;<span class="pl-c1">7</span>) lcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1106" class="blob-num js-line-number" data-line-number="1106"></td>
        <td id="LC1106" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1107" class="blob-num js-line-number" data-line-number="1107"></td>
        <td id="LC1107" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>((clvalue&gt;&gt;(<span class="pl-c1">8</span>+lcount))&amp;<span class="pl-c1">1</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L1108" class="blob-num js-line-number" data-line-number="1108"></td>
        <td id="LC1108" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1109" class="blob-num js-line-number" data-line-number="1109"></td>
        <td id="LC1109" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1110" class="blob-num js-line-number" data-line-number="1110"></td>
        <td id="LC1110" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)){</td>
      </tr>
      <tr>
        <td id="L1111" class="blob-num js-line-number" data-line-number="1111"></td>
        <td id="LC1111" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1112" class="blob-num js-line-number" data-line-number="1112"></td>
        <td id="LC1112" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1113" class="blob-num js-line-number" data-line-number="1113"></td>
        <td id="LC1113" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1114" class="blob-num js-line-number" data-line-number="1114"></td>
        <td id="LC1114" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1115" class="blob-num js-line-number" data-line-number="1115"></td>
        <td id="LC1115" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1116" class="blob-num js-line-number" data-line-number="1116"></td>
        <td id="LC1116" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1117" class="blob-num js-line-number" data-line-number="1117"></td>
        <td id="LC1117" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1118" class="blob-num js-line-number" data-line-number="1118"></td>
        <td id="LC1118" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">25</span>: <span class="pl-c"><span class="pl-c">//</span> was 47</span></td>
      </tr>
      <tr>
        <td id="L1119" class="blob-num js-line-number" data-line-number="1119"></td>
        <td id="LC1119" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> *we could use CV to set length of pulse (say up to 128 which is 7 bits &gt;&gt; 9)*</span></td>
      </tr>
      <tr>
        <td id="L1120" class="blob-num js-line-number" data-line-number="1120"></td>
        <td id="LC1120" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; as mode 14=speed divider with XOR rungler: XOR out with input bit</span></td>
      </tr>
      <tr>
        <td id="L1121" class="blob-num js-line-number" data-line-number="1121"></td>
        <td id="LC1121" class="blob-code blob-code-inner js-file-line">      	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING! - not so exciting ....</span></td>
      </tr>
      <tr>
        <td id="L1122" class="blob-num js-line-number" data-line-number="1122"></td>
        <td id="LC1122" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1123" class="blob-num js-line-number" data-line-number="1123"></td>
        <td id="LC1123" class="blob-code blob-code-inner js-file-line">      shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((bitl) ^ (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)));</td>
      </tr>
      <tr>
        <td id="L1124" class="blob-num js-line-number" data-line-number="1124"></td>
        <td id="LC1124" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1125" class="blob-num js-line-number" data-line-number="1125"></td>
        <td id="LC1125" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) {</td>
      </tr>
      <tr>
        <td id="L1126" class="blob-num js-line-number" data-line-number="1126"></td>
        <td id="LC1126" class="blob-code blob-code-inner js-file-line">	  GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1127" class="blob-num js-line-number" data-line-number="1127"></td>
        <td id="LC1127" class="blob-code blob-code-inner js-file-line">	  <span class="pl-c1">delay</span>(clvalue&gt;&gt;<span class="pl-c1">9</span>); <span class="pl-c"><span class="pl-c">//</span> 64=10uS - short = lower voltage...</span></td>
      </tr>
      <tr>
        <td id="L1128" class="blob-num js-line-number" data-line-number="1128"></td>
        <td id="LC1128" class="blob-code blob-code-inner js-file-line">	  GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1129" class="blob-num js-line-number" data-line-number="1129"></td>
        <td id="LC1129" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L1130" class="blob-num js-line-number" data-line-number="1130"></td>
        <td id="LC1130" class="blob-code blob-code-inner js-file-line">	  </td>
      </tr>
      <tr>
        <td id="L1131" class="blob-num js-line-number" data-line-number="1131"></td>
        <td id="LC1131" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) {</td>
      </tr>
      <tr>
        <td id="L1132" class="blob-num js-line-number" data-line-number="1132"></td>
        <td id="LC1132" class="blob-code blob-code-inner js-file-line">	  GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1133" class="blob-num js-line-number" data-line-number="1133"></td>
        <td id="LC1133" class="blob-code blob-code-inner js-file-line">	  <span class="pl-c1">delay</span>(clvalue&gt;&gt;<span class="pl-c1">9</span>); <span class="pl-c"><span class="pl-c">//</span> 64=10uS</span></td>
      </tr>
      <tr>
        <td id="L1134" class="blob-num js-line-number" data-line-number="1134"></td>
        <td id="LC1134" class="blob-code blob-code-inner js-file-line">	  GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1135" class="blob-num js-line-number" data-line-number="1135"></td>
        <td id="LC1135" class="blob-code blob-code-inner js-file-line">	  }</td>
      </tr>
      <tr>
        <td id="L1136" class="blob-num js-line-number" data-line-number="1136"></td>
        <td id="LC1136" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1137" class="blob-num js-line-number" data-line-number="1137"></td>
        <td id="LC1137" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1138" class="blob-num js-line-number" data-line-number="1138"></td>
        <td id="LC1138" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">26</span>: <span class="pl-c"><span class="pl-c">//</span> was 51</span></td>
      </tr>
      <tr>
        <td id="L1139" class="blob-num js-line-number" data-line-number="1139"></td>
        <td id="LC1139" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1140" class="blob-num js-line-number" data-line-number="1140"></td>
        <td id="LC1140" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1141" class="blob-num js-line-number" data-line-number="1141"></td>
        <td id="LC1141" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1142" class="blob-num js-line-number" data-line-number="1142"></td>
        <td id="LC1142" class="blob-code blob-code-inner js-file-line">      probl=clvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1143" class="blob-num js-line-number" data-line-number="1143"></td>
        <td id="LC1143" class="blob-code blob-code-inner js-file-line">      probl=electroprob[probl];</td>
      </tr>
      <tr>
        <td id="L1144" class="blob-num js-line-number" data-line-number="1144"></td>
        <td id="LC1144" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1145" class="blob-num js-line-number" data-line-number="1145"></td>
        <td id="LC1145" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probl | shift_registerh) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>); </td>
      </tr>
      <tr>
        <td id="L1146" class="blob-num js-line-number" data-line-number="1146"></td>
        <td id="LC1146" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1147" class="blob-num js-line-number" data-line-number="1147"></td>
        <td id="LC1147" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1148" class="blob-num js-line-number" data-line-number="1148"></td>
        <td id="LC1148" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)){</td>
      </tr>
      <tr>
        <td id="L1149" class="blob-num js-line-number" data-line-number="1149"></td>
        <td id="LC1149" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1150" class="blob-num js-line-number" data-line-number="1150"></td>
        <td id="LC1150" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1151" class="blob-num js-line-number" data-line-number="1151"></td>
        <td id="LC1151" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1152" class="blob-num js-line-number" data-line-number="1152"></td>
        <td id="LC1152" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1153" class="blob-num js-line-number" data-line-number="1153"></td>
        <td id="LC1153" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1154" class="blob-num js-line-number" data-line-number="1154"></td>
        <td id="LC1154" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1155" class="blob-num js-line-number" data-line-number="1155"></td>
        <td id="LC1155" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1156" class="blob-num js-line-number" data-line-number="1156"></td>
        <td id="LC1156" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">27</span>: <span class="pl-c"><span class="pl-c">//</span> was 52</span></td>
      </tr>
      <tr>
        <td id="L1157" class="blob-num js-line-number" data-line-number="1157"></td>
        <td id="LC1157" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1158" class="blob-num js-line-number" data-line-number="1158"></td>
        <td id="LC1158" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1159" class="blob-num js-line-number" data-line-number="1159"></td>
        <td id="LC1159" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>)){</td>
      </tr>
      <tr>
        <td id="L1160" class="blob-num js-line-number" data-line-number="1160"></td>
        <td id="LC1160" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1161" class="blob-num js-line-number" data-line-number="1161"></td>
        <td id="LC1161" class="blob-code blob-code-inner js-file-line">      probl=clvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1162" class="blob-num js-line-number" data-line-number="1162"></td>
        <td id="LC1162" class="blob-code blob-code-inner js-file-line">      probl=electroprob[probl];</td>
      </tr>
      <tr>
        <td id="L1163" class="blob-num js-line-number" data-line-number="1163"></td>
        <td id="LC1163" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1164" class="blob-num js-line-number" data-line-number="1164"></td>
        <td id="LC1164" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probl | shift_registerh) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>); </td>
      </tr>
      <tr>
        <td id="L1165" class="blob-num js-line-number" data-line-number="1165"></td>
        <td id="LC1165" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1166" class="blob-num js-line-number" data-line-number="1166"></td>
        <td id="LC1166" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1167" class="blob-num js-line-number" data-line-number="1167"></td>
        <td id="LC1167" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1168" class="blob-num js-line-number" data-line-number="1168"></td>
        <td id="LC1168" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1169" class="blob-num js-line-number" data-line-number="1169"></td>
        <td id="LC1169" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1170" class="blob-num js-line-number" data-line-number="1170"></td>
        <td id="LC1170" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1171" class="blob-num js-line-number" data-line-number="1171"></td>
        <td id="LC1171" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1172" class="blob-num js-line-number" data-line-number="1172"></td>
        <td id="LC1172" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1173" class="blob-num js-line-number" data-line-number="1173"></td>
        <td id="LC1173" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1174" class="blob-num js-line-number" data-line-number="1174"></td>
        <td id="LC1174" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">28</span>: <span class="pl-c"><span class="pl-c">//</span> was 53</span></td>
      </tr>
      <tr>
        <td id="L1175" class="blob-num js-line-number" data-line-number="1175"></td>
        <td id="LC1175" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits</span></td>
      </tr>
      <tr>
        <td id="L1176" class="blob-num js-line-number" data-line-number="1176"></td>
        <td id="LC1176" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> change and Re_test this - TESTED/working</span></td>
      </tr>
      <tr>
        <td id="L1177" class="blob-num js-line-number" data-line-number="1177"></td>
        <td id="LC1177" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> loop bitl back in XOR at certain point?</span></td>
      </tr>
      <tr>
        <td id="L1178" class="blob-num js-line-number" data-line-number="1178"></td>
        <td id="LC1178" class="blob-code blob-code-inner js-file-line">	bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1179" class="blob-num js-line-number" data-line-number="1179"></td>
        <td id="LC1179" class="blob-code blob-code-inner js-file-line">	shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1180" class="blob-num js-line-number" data-line-number="1180"></td>
        <td id="LC1180" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> do the loop back in</span></td>
      </tr>
      <tr>
        <td id="L1181" class="blob-num js-line-number" data-line-number="1181"></td>
        <td id="LC1181" class="blob-code blob-code-inner js-file-line">	lcount=clvalue&gt;&gt;<span class="pl-c1">11</span>; <span class="pl-c"><span class="pl-c">//</span> 5 bits - or: lcount=(clvalue&gt;&gt;11)%(SRlengthl+1);</span></td>
      </tr>
      <tr>
        <td id="L1182" class="blob-num js-line-number" data-line-number="1182"></td>
        <td id="LC1182" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) shift_registerl ^= (<span class="pl-c1">1</span>&lt;&lt;lcount);<span class="pl-c"><span class="pl-c">//</span> set the xth bit</span></td>
      </tr>
      <tr>
        <td id="L1183" class="blob-num js-line-number" data-line-number="1183"></td>
        <td id="LC1183" class="blob-code blob-code-inner js-file-line">	shift_registerl ^= (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>));</td>
      </tr>
      <tr>
        <td id="L1184" class="blob-num js-line-number" data-line-number="1184"></td>
        <td id="LC1184" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1185" class="blob-num js-line-number" data-line-number="1185"></td>
        <td id="LC1185" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1186" class="blob-num js-line-number" data-line-number="1186"></td>
        <td id="LC1186" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1187" class="blob-num js-line-number" data-line-number="1187"></td>
        <td id="LC1187" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1188" class="blob-num js-line-number" data-line-number="1188"></td>
        <td id="LC1188" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1189" class="blob-num js-line-number" data-line-number="1189"></td>
        <td id="LC1189" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1190" class="blob-num js-line-number" data-line-number="1190"></td>
        <td id="LC1190" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1191" class="blob-num js-line-number" data-line-number="1191"></td>
        <td id="LC1191" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">29</span>: <span class="pl-c"><span class="pl-c">//</span> was 56</span></td>
      </tr>
      <tr>
        <td id="L1192" class="blob-num js-line-number" data-line-number="1192"></td>
        <td id="LC1192" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1193" class="blob-num js-line-number" data-line-number="1193"></td>
        <td id="LC1193" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> can use CV as length of either SR = here is regularSR</span></td>
      </tr>
      <tr>
        <td id="L1194" class="blob-num js-line-number" data-line-number="1194"></td>
        <td id="LC1194" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>       - TESTED/working</span></td>
      </tr>
      <tr>
        <td id="L1195" class="blob-num js-line-number" data-line-number="1195"></td>
        <td id="LC1195" class="blob-code blob-code-inner js-file-line">      SRlengthl=(clvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1196" class="blob-num js-line-number" data-line-number="1196"></td>
        <td id="LC1196" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthl&lt;<span class="pl-c1">4</span>) SRlengthl=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1197" class="blob-num js-line-number" data-line-number="1197"></td>
        <td id="LC1197" class="blob-code blob-code-inner js-file-line">      lengthbitl=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthl/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L1198" class="blob-num js-line-number" data-line-number="1198"></td>
        <td id="LC1198" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1199" class="blob-num js-line-number" data-line-number="1199"></td>
        <td id="LC1199" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerxl==<span class="pl-c1">0</span>) shift_registerxl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L1200" class="blob-num js-line-number" data-line-number="1200"></td>
        <td id="LC1200" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bitl= ((shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl &gt;&gt; (lfsr_taps_mirrored[SRlengthl][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1201" class="blob-num js-line-number" data-line-number="1201"></td>
        <td id="LC1201" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerxl &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerxl &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1202" class="blob-num js-line-number" data-line-number="1202"></td>
        <td id="LC1202" class="blob-code blob-code-inner js-file-line">	shift_registerxl = (shift_registerxl&lt;&lt;<span class="pl-c1">1</span>) + bitl; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerxl = (shift_registerx&lt;&lt;1) + (bitl | !(GPIOB-&gt;IDR &amp; 0x0040)); </span></td>
      </tr>
      <tr>
        <td id="L1203" class="blob-num js-line-number" data-line-number="1203"></td>
        <td id="LC1203" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1204" class="blob-num js-line-number" data-line-number="1204"></td>
        <td id="LC1204" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bitl with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L1205" class="blob-num js-line-number" data-line-number="1205"></td>
        <td id="LC1205" class="blob-code blob-code-inner js-file-line">	  bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L1206" class="blob-num js-line-number" data-line-number="1206"></td>
        <td id="LC1206" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1207" class="blob-num js-line-number" data-line-number="1207"></td>
        <td id="LC1207" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L1208" class="blob-num js-line-number" data-line-number="1208"></td>
        <td id="LC1208" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1209" class="blob-num js-line-number" data-line-number="1209"></td>
        <td id="LC1209" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1210" class="blob-num js-line-number" data-line-number="1210"></td>
        <td id="LC1210" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1211" class="blob-num js-line-number" data-line-number="1211"></td>
        <td id="LC1211" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1212" class="blob-num js-line-number" data-line-number="1212"></td>
        <td id="LC1212" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1213" class="blob-num js-line-number" data-line-number="1213"></td>
        <td id="LC1213" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L1214" class="blob-num js-line-number" data-line-number="1214"></td>
        <td id="LC1214" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1215" class="blob-num js-line-number" data-line-number="1215"></td>
        <td id="LC1215" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1216" class="blob-num js-line-number" data-line-number="1216"></td>
        <td id="LC1216" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">30</span>: <span class="pl-c"><span class="pl-c">//</span> was 57</span></td>
      </tr>
      <tr>
        <td id="L1217" class="blob-num js-line-number" data-line-number="1217"></td>
        <td id="LC1217" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1218" class="blob-num js-line-number" data-line-number="1218"></td>
        <td id="LC1218" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> can use CV as length of either SR = here is SRx</span></td>
      </tr>
      <tr>
        <td id="L1219" class="blob-num js-line-number" data-line-number="1219"></td>
        <td id="LC1219" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>       - TESTED/working but not so satisfying for clvalue use</span></td>
      </tr>
      <tr>
        <td id="L1220" class="blob-num js-line-number" data-line-number="1220"></td>
        <td id="LC1220" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1221" class="blob-num js-line-number" data-line-number="1221"></td>
        <td id="LC1221" class="blob-code blob-code-inner js-file-line">      SRlengthx=(clvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1222" class="blob-num js-line-number" data-line-number="1222"></td>
        <td id="LC1222" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthx&lt;<span class="pl-c1">4</span>) SRlengthx=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1223" class="blob-num js-line-number" data-line-number="1223"></td>
        <td id="LC1223" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1224" class="blob-num js-line-number" data-line-number="1224"></td>
        <td id="LC1224" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerxl==<span class="pl-c1">0</span>) shift_registerxl=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L1225" class="blob-num js-line-number" data-line-number="1225"></td>
        <td id="LC1225" class="blob-code blob-code-inner js-file-line">	bitl= ((shift_registerxl &gt;&gt; (lfsr_taps_mirrored[SRlengthx][<span class="pl-c1">0</span>])) ^ (shift_registerxl &gt;&gt; (lfsr_taps_mirrored[SRlengthx][<span class="pl-c1">1</span>])) ^ (shift_registerxl &gt;&gt; (lfsr_taps_mirrored[SRlengthx][<span class="pl-c1">2</span>])) ^ (shift_registerxl &gt;&gt; (lfsr_taps_mirrored[SRlengthx][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1226" class="blob-num js-line-number" data-line-number="1226"></td>
        <td id="LC1226" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bitl= ((shift_registerx &gt;&gt; 31) ^ (shift_registerx &gt;&gt; 29) ^ (shift_registerx &gt;&gt; 25) ^ (shift_registerx &gt;&gt; 24)) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1227" class="blob-num js-line-number" data-line-number="1227"></td>
        <td id="LC1227" class="blob-code blob-code-inner js-file-line">	shift_registerxl = (shift_registerxl&lt;&lt;<span class="pl-c1">1</span>) + bitl; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bitl | !(GPIOB-&gt;IDR &amp; 0x0040)); </span></td>
      </tr>
      <tr>
        <td id="L1228" class="blob-num js-line-number" data-line-number="1228"></td>
        <td id="LC1228" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1229" class="blob-num js-line-number" data-line-number="1229"></td>
        <td id="LC1229" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bitl){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bitl with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L1230" class="blob-num js-line-number" data-line-number="1230"></td>
        <td id="LC1230" class="blob-code blob-code-inner js-file-line">	  bitl = (shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L1231" class="blob-num js-line-number" data-line-number="1231"></td>
        <td id="LC1231" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + bitl;</td>
      </tr>
      <tr>
        <td id="L1232" class="blob-num js-line-number" data-line-number="1232"></td>
        <td id="LC1232" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;<span class="pl-c1">1</span>) + (!bitl);</td>
      </tr>
      <tr>
        <td id="L1233" class="blob-num js-line-number" data-line-number="1233"></td>
        <td id="LC1233" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1234" class="blob-num js-line-number" data-line-number="1234"></td>
        <td id="LC1234" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1235" class="blob-num js-line-number" data-line-number="1235"></td>
        <td id="LC1235" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1236" class="blob-num js-line-number" data-line-number="1236"></td>
        <td id="LC1236" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1237" class="blob-num js-line-number" data-line-number="1237"></td>
        <td id="LC1237" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1238" class="blob-num js-line-number" data-line-number="1238"></td>
        <td id="LC1238" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L1239" class="blob-num js-line-number" data-line-number="1239"></td>
        <td id="LC1239" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1240" class="blob-num js-line-number" data-line-number="1240"></td>
        <td id="LC1240" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1241" class="blob-num js-line-number" data-line-number="1241"></td>
        <td id="LC1241" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">31</span>: <span class="pl-c"><span class="pl-c">//</span> was 58 -  change the shifting amount - sort of works but not a great range and we need to take care of length</span></td>
      </tr>
      <tr>
        <td id="L1242" class="blob-num js-line-number" data-line-number="1242"></td>
        <td id="LC1242" class="blob-code blob-code-inner js-file-line">      shifter=(clvalue&gt;&gt;<span class="pl-c1">11</span>)%(SRlengthl+<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1243" class="blob-num js-line-number" data-line-number="1243"></td>
        <td id="LC1243" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shifter==<span class="pl-c1">0</span>) shifter=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1244" class="blob-num js-line-number" data-line-number="1244"></td>
        <td id="LC1244" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TM here</span></td>
      </tr>
      <tr>
        <td id="L1245" class="blob-num js-line-number" data-line-number="1245"></td>
        <td id="LC1245" class="blob-code blob-code-inner js-file-line">      bitl = (shift_registerl&gt;&gt;(SRlengthl-(shifter-<span class="pl-c1">1</span>))) &amp; (shifter); <span class="pl-c"><span class="pl-c">//</span> bits which would be shifted out  // 1 for length of 31</span></td>
      </tr>
      <tr>
        <td id="L1246" class="blob-num js-line-number" data-line-number="1246"></td>
        <td id="LC1246" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0040</span>) shift_registerl = (shift_registerl&lt;&lt;shifter) + bitl;</td>
      </tr>
      <tr>
        <td id="L1247" class="blob-num js-line-number" data-line-number="1247"></td>
        <td id="LC1247" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerl = (shift_registerl&lt;&lt;shifter) + (~bitl);</td>
      </tr>
      <tr>
        <td id="L1248" class="blob-num js-line-number" data-line-number="1248"></td>
        <td id="LC1248" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1249" class="blob-num js-line-number" data-line-number="1249"></td>
        <td id="LC1249" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1250" class="blob-num js-line-number" data-line-number="1250"></td>
        <td id="LC1250" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1251" class="blob-num js-line-number" data-line-number="1251"></td>
        <td id="LC1251" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerl &amp; lengthbitl) GPIOB-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1252" class="blob-num js-line-number" data-line-number="1252"></td>
        <td id="LC1252" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOB-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1253" class="blob-num js-line-number" data-line-number="1253"></td>
        <td id="LC1253" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1254" class="blob-num js-line-number" data-line-number="1254"></td>
        <td id="LC1254" class="blob-code blob-code-inner js-file-line">    }       <span class="pl-c"><span class="pl-c">//</span>/ end of LF modes</span></td>
      </tr>
      <tr>
        <td id="L1255" class="blob-num js-line-number" data-line-number="1255"></td>
        <td id="LC1255" class="blob-code blob-code-inner js-file-line">  }</td>
      </tr>
      <tr>
        <td id="L1256" class="blob-num js-line-number" data-line-number="1256"></td>
        <td id="LC1256" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1257" class="blob-num js-line-number" data-line-number="1257"></td>
        <td id="LC1257" class="blob-code blob-code-inner js-file-line">  <span class="pl-c"><span class="pl-c">//</span> --------------------HF Pulse modes </span></td>
      </tr>
      <tr>
        <td id="L1258" class="blob-num js-line-number" data-line-number="1258"></td>
        <td id="LC1258" class="blob-code blob-code-inner js-file-line">  <span class="pl-k">if</span>(pending &amp; (<span class="pl-c1">1</span> &lt;&lt; <span class="pl-c1">7</span>)) { <span class="pl-c"><span class="pl-c">//</span> HF on 7/out on C</span></td>
      </tr>
      <tr>
        <td id="L1259" class="blob-num js-line-number" data-line-number="1259"></td>
        <td id="LC1259" class="blob-code blob-code-inner js-file-line">    EXTI-&gt;<span class="pl-smi">PR</span> = <span class="pl-c1">1</span> &lt;&lt; <span class="pl-c1">7</span>;        <span class="pl-c"><span class="pl-c">//</span> handle pin 7 here</span></td>
      </tr>
      <tr>
        <td id="L1260" class="blob-num js-line-number" data-line-number="1260"></td>
        <td id="LC1260" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span>    hfpulsecount++;</span></td>
      </tr>
      <tr>
        <td id="L1261" class="blob-num js-line-number" data-line-number="1261"></td>
        <td id="LC1261" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1262" class="blob-num js-line-number" data-line-number="1262"></td>
        <td id="LC1262" class="blob-code blob-code-inner js-file-line">    <span class="pl-c"><span class="pl-c">//</span> TESTY = our mode inversion</span></td>
      </tr>
      <tr>
        <td id="L1263" class="blob-num js-line-number" data-line-number="1263"></td>
        <td id="LC1263" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span> (modehpwm==<span class="pl-c1">0</span>) cvalue=<span class="pl-c1">65536</span>-ADCBuffer[<span class="pl-c1">2</span>];  <span class="pl-c"><span class="pl-c">//</span> or modehpwm&gt;1???TESTY!</span></td>
      </tr>
      <tr>
        <td id="L1264" class="blob-num js-line-number" data-line-number="1264"></td>
        <td id="LC1264" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">else</span> cvalue=ADCBuffer[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L1265" class="blob-num js-line-number" data-line-number="1265"></td>
        <td id="LC1265" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1266" class="blob-num js-line-number" data-line-number="1266"></td>
        <td id="LC1266" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span>*PULSE_HF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 48, 50, 52, 53, 56, 57, 58*</span></td>
      </tr>
      <tr>
        <td id="L1267" class="blob-num js-line-number" data-line-number="1267"></td>
        <td id="LC1267" class="blob-code blob-code-inner js-file-line">    </td>
      </tr>
      <tr>
        <td id="L1268" class="blob-num js-line-number" data-line-number="1268"></td>
        <td id="LC1268" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">switch</span>(modehsr){</td>
      </tr>
      <tr>
        <td id="L1269" class="blob-num js-line-number" data-line-number="1269"></td>
        <td id="LC1269" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">16</span>: <span class="pl-c"><span class="pl-c">//</span> was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO</span></td>
      </tr>
      <tr>
        <td id="L1270" class="blob-num js-line-number" data-line-number="1270"></td>
        <td id="LC1270" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; CV selects length of SR which will stay with us .. -&gt; LFSR here</span></td>
      </tr>
      <tr>
        <td id="L1271" class="blob-num js-line-number" data-line-number="1271"></td>
        <td id="LC1271" class="blob-code blob-code-inner js-file-line">      SRlengthh=<span class="pl-c1">31</span>-(cvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1272" class="blob-num js-line-number" data-line-number="1272"></td>
        <td id="LC1272" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthh&lt;<span class="pl-c1">4</span>) SRlengthh=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1273" class="blob-num js-line-number" data-line-number="1273"></td>
        <td id="LC1273" class="blob-code blob-code-inner js-file-line">      lengthbith=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthh/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L1274" class="blob-num js-line-number" data-line-number="1274"></td>
        <td id="LC1274" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh==<span class="pl-c1">0</span>) shift_registerh=<span class="pl-c1">0xff</span>;</td>
      </tr>
      <tr>
        <td id="L1275" class="blob-num js-line-number" data-line-number="1275"></td>
        <td id="LC1275" class="blob-code blob-code-inner js-file-line">      bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">0</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">1</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">2</span>])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1276" class="blob-num js-line-number" data-line-number="1276"></td>
        <td id="LC1276" class="blob-code blob-code-inner js-file-line">      shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((bith | !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>))); <span class="pl-c"><span class="pl-c">//</span> PB7 and PB10</span></td>
      </tr>
      <tr>
        <td id="L1277" class="blob-num js-line-number" data-line-number="1277"></td>
        <td id="LC1277" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1278" class="blob-num js-line-number" data-line-number="1278"></td>
        <td id="LC1278" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1279" class="blob-num js-line-number" data-line-number="1279"></td>
        <td id="LC1279" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1280" class="blob-num js-line-number" data-line-number="1280"></td>
        <td id="LC1280" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1281" class="blob-num js-line-number" data-line-number="1281"></td>
        <td id="LC1281" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1282" class="blob-num js-line-number" data-line-number="1282"></td>
        <td id="LC1282" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1283" class="blob-num js-line-number" data-line-number="1283"></td>
        <td id="LC1283" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1284" class="blob-num js-line-number" data-line-number="1284"></td>
        <td id="LC1284" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">17</span>: <span class="pl-c"><span class="pl-c">//</span> was 10</span></td>
      </tr>
      <tr>
        <td id="L1285" class="blob-num js-line-number" data-line-number="1285"></td>
        <td id="LC1285" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit </span></td>
      </tr>
      <tr>
        <td id="L1286" class="blob-num js-line-number" data-line-number="1286"></td>
        <td id="LC1286" class="blob-code blob-code-inner js-file-line">      hcount++;</td>
      </tr>
      <tr>
        <td id="L1287" class="blob-num js-line-number" data-line-number="1287"></td>
        <td id="LC1287" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">7</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1288" class="blob-num js-line-number" data-line-number="1288"></td>
        <td id="LC1288" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1289" class="blob-num js-line-number" data-line-number="1289"></td>
        <td id="LC1289" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1290" class="blob-num js-line-number" data-line-number="1290"></td>
        <td id="LC1290" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span>((cvalue&gt;&gt;(<span class="pl-c1">8</span>+hcount))&amp;<span class="pl-c1">1</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L1291" class="blob-num js-line-number" data-line-number="1291"></td>
        <td id="LC1291" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1292" class="blob-num js-line-number" data-line-number="1292"></td>
        <td id="LC1292" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1293" class="blob-num js-line-number" data-line-number="1293"></td>
        <td id="LC1293" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1294" class="blob-num js-line-number" data-line-number="1294"></td>
        <td id="LC1294" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1295" class="blob-num js-line-number" data-line-number="1295"></td>
        <td id="LC1295" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1296" class="blob-num js-line-number" data-line-number="1296"></td>
        <td id="LC1296" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1297" class="blob-num js-line-number" data-line-number="1297"></td>
        <td id="LC1297" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1298" class="blob-num js-line-number" data-line-number="1298"></td>
        <td id="LC1298" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1299" class="blob-num js-line-number" data-line-number="1299"></td>
        <td id="LC1299" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">18</span>: <span class="pl-c"><span class="pl-c">//</span> was 12 - works fine with cv in</span></td>
      </tr>
      <tr>
        <td id="L1300" class="blob-num js-line-number" data-line-number="1300"></td>
        <td id="LC1300" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; NEW mode TESTY: entry of ADC in from CV into upper bits?</span></td>
      </tr>
      <tr>
        <td id="L1301" class="blob-num js-line-number" data-line-number="1301"></td>
        <td id="LC1301" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1302" class="blob-num js-line-number" data-line-number="1302"></td>
        <td id="LC1302" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1303" class="blob-num js-line-number" data-line-number="1303"></td>
        <td id="LC1303" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (counter12h == <span class="pl-c1">9</span>){       <span class="pl-c"><span class="pl-c">//</span> every 8 cycles</span></td>
      </tr>
      <tr>
        <td id="L1304" class="blob-num js-line-number" data-line-number="1304"></td>
        <td id="LC1304" class="blob-code blob-code-inner js-file-line">	counter12h=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1305" class="blob-num js-line-number" data-line-number="1305"></td>
        <td id="LC1305" class="blob-code blob-code-inner js-file-line">	shift_registerh &amp;= MASK[SRlengthh]; <span class="pl-c"><span class="pl-c">//</span> MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths</span></td>
      </tr>
      <tr>
        <td id="L1306" class="blob-num js-line-number" data-line-number="1306"></td>
        <td id="LC1306" class="blob-code blob-code-inner js-file-line">	shift_registerh +=(cvalue&gt;&gt;<span class="pl-c1">8</span>)&lt;&lt;(SHIFT[SRlengthh]); </td>
      </tr>
      <tr>
        <td id="L1307" class="blob-num js-line-number" data-line-number="1307"></td>
        <td id="LC1307" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1308" class="blob-num js-line-number" data-line-number="1308"></td>
        <td id="LC1308" class="blob-code blob-code-inner js-file-line">      counter12h++;</td>
      </tr>
      <tr>
        <td id="L1309" class="blob-num js-line-number" data-line-number="1309"></td>
        <td id="LC1309" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1310" class="blob-num js-line-number" data-line-number="1310"></td>
        <td id="LC1310" class="blob-code blob-code-inner js-file-line">      shift_registerh=(shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (bith |  (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>))); <span class="pl-c"><span class="pl-c">//</span> cycle around and OR in pulse bit! TESTY!</span></td>
      </tr>
      <tr>
        <td id="L1311" class="blob-num js-line-number" data-line-number="1311"></td>
        <td id="LC1311" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1312" class="blob-num js-line-number" data-line-number="1312"></td>
        <td id="LC1312" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1313" class="blob-num js-line-number" data-line-number="1313"></td>
        <td id="LC1313" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1314" class="blob-num js-line-number" data-line-number="1314"></td>
        <td id="LC1314" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1315" class="blob-num js-line-number" data-line-number="1315"></td>
        <td id="LC1315" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1316" class="blob-num js-line-number" data-line-number="1316"></td>
        <td id="LC1316" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1317" class="blob-num js-line-number" data-line-number="1317"></td>
        <td id="LC1317" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1318" class="blob-num js-line-number" data-line-number="1318"></td>
        <td id="LC1318" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">19</span>: <span class="pl-c"><span class="pl-c">//</span> was 13</span></td>
      </tr>
      <tr>
        <td id="L1319" class="blob-num js-line-number" data-line-number="1319"></td>
        <td id="LC1319" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1320" class="blob-num js-line-number" data-line-number="1320"></td>
        <td id="LC1320" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> we do not use bit IN!</span></td>
      </tr>
      <tr>
        <td id="L1321" class="blob-num js-line-number" data-line-number="1321"></td>
        <td id="LC1321" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1322" class="blob-num js-line-number" data-line-number="1322"></td>
        <td id="LC1322" class="blob-code blob-code-inner js-file-line">      probh=cvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1323" class="blob-num js-line-number" data-line-number="1323"></td>
        <td id="LC1323" class="blob-code blob-code-inner js-file-line">      probh=electroprob[probh];</td>
      </tr>
      <tr>
        <td id="L1324" class="blob-num js-line-number" data-line-number="1324"></td>
        <td id="LC1324" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1325" class="blob-num js-line-number" data-line-number="1325"></td>
        <td id="LC1325" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> new bits enter from shiftregleft - 0xff was looker[7]</span></td>
      </tr>
      <tr>
        <td id="L1326" class="blob-num js-line-number" data-line-number="1326"></td>
        <td id="LC1326" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1327" class="blob-num js-line-number" data-line-number="1327"></td>
        <td id="LC1327" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1328" class="blob-num js-line-number" data-line-number="1328"></td>
        <td id="LC1328" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1329" class="blob-num js-line-number" data-line-number="1329"></td>
        <td id="LC1329" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1330" class="blob-num js-line-number" data-line-number="1330"></td>
        <td id="LC1330" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1331" class="blob-num js-line-number" data-line-number="1331"></td>
        <td id="LC1331" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1332" class="blob-num js-line-number" data-line-number="1332"></td>
        <td id="LC1332" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1333" class="blob-num js-line-number" data-line-number="1333"></td>
        <td id="LC1333" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1334" class="blob-num js-line-number" data-line-number="1334"></td>
        <td id="LC1334" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">20</span>: <span class="pl-c"><span class="pl-c">//</span> was 14 - could replace mode or one of these ???</span></td>
      </tr>
      <tr>
        <td id="L1335" class="blob-num js-line-number" data-line-number="1335"></td>
        <td id="LC1335" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; uses CV as speed/flipflop/clock divider</span></td>
      </tr>
      <tr>
        <td id="L1336" class="blob-num js-line-number" data-line-number="1336"></td>
        <td id="LC1336" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit</span></td>
      </tr>
      <tr>
        <td id="L1337" class="blob-num js-line-number" data-line-number="1337"></td>
        <td id="LC1337" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1338" class="blob-num js-line-number" data-line-number="1338"></td>
        <td id="LC1338" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      origbith=bith;</span></td>
      </tr>
      <tr>
        <td id="L1339" class="blob-num js-line-number" data-line-number="1339"></td>
        <td id="LC1339" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh =  (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1340" class="blob-num js-line-number" data-line-number="1340"></td>
        <td id="LC1340" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L1341" class="blob-num js-line-number" data-line-number="1341"></td>
        <td id="LC1341" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1342" class="blob-num js-line-number" data-line-number="1342"></td>
        <td id="LC1342" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1</span></td>
      </tr>
      <tr>
        <td id="L1343" class="blob-num js-line-number" data-line-number="1343"></td>
        <td id="LC1343" class="blob-code blob-code-inner js-file-line">      numflips=(cvalue&gt;&gt;<span class="pl-c1">12</span>); <span class="pl-c"><span class="pl-c">//</span>or 15-(cvalue&gt;&gt;12) if we wish it to go in the opposite direction</span></td>
      </tr>
      <tr>
        <td id="L1344" class="blob-num js-line-number" data-line-number="1344"></td>
        <td id="LC1344" class="blob-code blob-code-inner js-file-line">      new_state[<span class="pl-c1">0</span>]=bith;</td>
      </tr>
      <tr>
        <td id="L1345" class="blob-num js-line-number" data-line-number="1345"></td>
        <td id="LC1345" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (prev_state[<span class="pl-c1">0</span>]==<span class="pl-c1">0</span> &amp;&amp; new_state[<span class="pl-c1">0</span>]==<span class="pl-c1">1</span>) flipped[<span class="pl-c1">0</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1346" class="blob-num js-line-number" data-line-number="1346"></td>
        <td id="LC1346" class="blob-code blob-code-inner js-file-line">      prev_state[<span class="pl-c1">0</span>]=new_state[<span class="pl-c1">0</span>];	</td>
      </tr>
      <tr>
        <td id="L1347" class="blob-num js-line-number" data-line-number="1347"></td>
        <td id="LC1347" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1348" class="blob-num js-line-number" data-line-number="1348"></td>
        <td id="LC1348" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">1</span>;x&lt;numflips;x++){ </td>
      </tr>
      <tr>
        <td id="L1349" class="blob-num js-line-number" data-line-number="1349"></td>
        <td id="LC1349" class="blob-code blob-code-inner js-file-line">	new_state[x]=flipped[x-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1350" class="blob-num js-line-number" data-line-number="1350"></td>
        <td id="LC1350" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_state[x]==<span class="pl-c1">0</span> &amp;&amp; new_state[x]==<span class="pl-c1">1</span>) flipped[x]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1351" class="blob-num js-line-number" data-line-number="1351"></td>
        <td id="LC1351" class="blob-code blob-code-inner js-file-line">	prev_state[x]=new_state[x];</td>
      </tr>
      <tr>
        <td id="L1352" class="blob-num js-line-number" data-line-number="1352"></td>
        <td id="LC1352" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1353" class="blob-num js-line-number" data-line-number="1353"></td>
        <td id="LC1353" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (numflips&gt;<span class="pl-c1">0</span>)	bith=flipped[numflips-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1354" class="blob-num js-line-number" data-line-number="1354"></td>
        <td id="LC1354" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1355" class="blob-num js-line-number" data-line-number="1355"></td>
        <td id="LC1355" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1356" class="blob-num js-line-number" data-line-number="1356"></td>
        <td id="LC1356" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1357" class="blob-num js-line-number" data-line-number="1357"></td>
        <td id="LC1357" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      if (origbith) GPIOC-&gt;BRR = 0b0100000000000000;  // original bith </span></td>
      </tr>
      <tr>
        <td id="L1358" class="blob-num js-line-number" data-line-number="1358"></td>
        <td id="LC1358" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      else GPIOC-&gt;BSRR = 0b0100000000000000;</span></td>
      </tr>
      <tr>
        <td id="L1359" class="blob-num js-line-number" data-line-number="1359"></td>
        <td id="LC1359" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) {</td>
      </tr>
      <tr>
        <td id="L1360" class="blob-num js-line-number" data-line-number="1360"></td>
        <td id="LC1360" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith)	GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1361" class="blob-num js-line-number" data-line-number="1361"></td>
        <td id="LC1361" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1362" class="blob-num js-line-number" data-line-number="1362"></td>
        <td id="LC1362" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1363" class="blob-num js-line-number" data-line-number="1363"></td>
        <td id="LC1363" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1364" class="blob-num js-line-number" data-line-number="1364"></td>
        <td id="LC1364" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1365" class="blob-num js-line-number" data-line-number="1365"></td>
        <td id="LC1365" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">21</span>: <span class="pl-c"><span class="pl-c">//</span> was 15</span></td>
      </tr>
      <tr>
        <td id="L1366" class="blob-num js-line-number" data-line-number="1366"></td>
        <td id="LC1366" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; as mode 14=speed divider with XOR rungler: XOR out with input bit</span></td>
      </tr>
      <tr>
        <td id="L1367" class="blob-num js-line-number" data-line-number="1367"></td>
        <td id="LC1367" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1368" class="blob-num js-line-number" data-line-number="1368"></td>
        <td id="LC1368" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      origbith=bith;</span></td>
      </tr>
      <tr>
        <td id="L1369" class="blob-num js-line-number" data-line-number="1369"></td>
        <td id="LC1369" class="blob-code blob-code-inner js-file-line">      shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((bith) ^ (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)));</td>
      </tr>
      <tr>
        <td id="L1370" class="blob-num js-line-number" data-line-number="1370"></td>
        <td id="LC1370" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1371" class="blob-num js-line-number" data-line-number="1371"></td>
        <td id="LC1371" class="blob-code blob-code-inner js-file-line">      numflips=(cvalue&gt;&gt;<span class="pl-c1">12</span>); <span class="pl-c"><span class="pl-c">//</span>or 15-(cvalue&gt;&gt;12) if we wish it to go in the opposite direction</span></td>
      </tr>
      <tr>
        <td id="L1372" class="blob-num js-line-number" data-line-number="1372"></td>
        <td id="LC1372" class="blob-code blob-code-inner js-file-line">      new_state[<span class="pl-c1">0</span>]=bith;</td>
      </tr>
      <tr>
        <td id="L1373" class="blob-num js-line-number" data-line-number="1373"></td>
        <td id="LC1373" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (prev_state[<span class="pl-c1">0</span>]==<span class="pl-c1">0</span> &amp;&amp; new_state[<span class="pl-c1">0</span>]==<span class="pl-c1">1</span>) flipped[<span class="pl-c1">0</span>]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1374" class="blob-num js-line-number" data-line-number="1374"></td>
        <td id="LC1374" class="blob-code blob-code-inner js-file-line">      prev_state[<span class="pl-c1">0</span>]=new_state[<span class="pl-c1">0</span>];	</td>
      </tr>
      <tr>
        <td id="L1375" class="blob-num js-line-number" data-line-number="1375"></td>
        <td id="LC1375" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1376" class="blob-num js-line-number" data-line-number="1376"></td>
        <td id="LC1376" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">1</span>;x&lt;numflips;x++){ </td>
      </tr>
      <tr>
        <td id="L1377" class="blob-num js-line-number" data-line-number="1377"></td>
        <td id="LC1377" class="blob-code blob-code-inner js-file-line">	new_state[x]=flipped[x-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1378" class="blob-num js-line-number" data-line-number="1378"></td>
        <td id="LC1378" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (prev_state[x]==<span class="pl-c1">0</span> &amp;&amp; new_state[x]==<span class="pl-c1">1</span>) flipped[x]^=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1379" class="blob-num js-line-number" data-line-number="1379"></td>
        <td id="LC1379" class="blob-code blob-code-inner js-file-line">	prev_state[x]=new_state[x];</td>
      </tr>
      <tr>
        <td id="L1380" class="blob-num js-line-number" data-line-number="1380"></td>
        <td id="LC1380" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1381" class="blob-num js-line-number" data-line-number="1381"></td>
        <td id="LC1381" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (numflips&gt;<span class="pl-c1">0</span>)	bith=flipped[numflips-<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1382" class="blob-num js-line-number" data-line-number="1382"></td>
        <td id="LC1382" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1383" class="blob-num js-line-number" data-line-number="1383"></td>
        <td id="LC1383" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1384" class="blob-num js-line-number" data-line-number="1384"></td>
        <td id="LC1384" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1385" class="blob-num js-line-number" data-line-number="1385"></td>
        <td id="LC1385" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) {</td>
      </tr>
      <tr>
        <td id="L1386" class="blob-num js-line-number" data-line-number="1386"></td>
        <td id="LC1386" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith)	GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1387" class="blob-num js-line-number" data-line-number="1387"></td>
        <td id="LC1387" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1388" class="blob-num js-line-number" data-line-number="1388"></td>
        <td id="LC1388" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1389" class="blob-num js-line-number" data-line-number="1389"></td>
        <td id="LC1389" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      if (origbith) GPIOC-&gt;BRR = 0b0100000000000000;  // original bith </span></td>
      </tr>
      <tr>
        <td id="L1390" class="blob-num js-line-number" data-line-number="1390"></td>
        <td id="LC1390" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      else GPIOC-&gt;BSRR = 0b0100000000000000;</span></td>
      </tr>
      <tr>
        <td id="L1391" class="blob-num js-line-number" data-line-number="1391"></td>
        <td id="LC1391" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1392" class="blob-num js-line-number" data-line-number="1392"></td>
        <td id="LC1392" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1393" class="blob-num js-line-number" data-line-number="1393"></td>
        <td id="LC1393" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">22</span>: <span class="pl-c"><span class="pl-c">//</span> was 43</span></td>
      </tr>
      <tr>
        <td id="L1394" class="blob-num js-line-number" data-line-number="1394"></td>
        <td id="LC1394" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as above but other way round with CV for length and incoming bits for probability of TM</span></td>
      </tr>
      <tr>
        <td id="L1395" class="blob-num js-line-number" data-line-number="1395"></td>
        <td id="LC1395" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1396" class="blob-num js-line-number" data-line-number="1396"></td>
        <td id="LC1396" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1397" class="blob-num js-line-number" data-line-number="1397"></td>
        <td id="LC1397" class="blob-code blob-code-inner js-file-line">      SRlengthh=<span class="pl-c1">31</span>-(cvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1398" class="blob-num js-line-number" data-line-number="1398"></td>
        <td id="LC1398" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthh&lt;<span class="pl-c1">4</span>) SRlengthh=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1399" class="blob-num js-line-number" data-line-number="1399"></td>
        <td id="LC1399" class="blob-code blob-code-inner js-file-line">      lengthbith=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthh/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L1400" class="blob-num js-line-number" data-line-number="1400"></td>
        <td id="LC1400" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1401" class="blob-num js-line-number" data-line-number="1401"></td>
        <td id="LC1401" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">7</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1402" class="blob-num js-line-number" data-line-number="1402"></td>
        <td id="LC1402" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span>( !(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)) probh^=(<span class="pl-c1">1</span>&lt;&lt;hcount);</td>
      </tr>
      <tr>
        <td id="L1403" class="blob-num js-line-number" data-line-number="1403"></td>
        <td id="LC1403" class="blob-code blob-code-inner js-file-line">      hcount++;</td>
      </tr>
      <tr>
        <td id="L1404" class="blob-num js-line-number" data-line-number="1404"></td>
        <td id="LC1404" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1405" class="blob-num js-line-number" data-line-number="1405"></td>
        <td id="LC1405" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1406" class="blob-num js-line-number" data-line-number="1406"></td>
        <td id="LC1406" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L1407" class="blob-num js-line-number" data-line-number="1407"></td>
        <td id="LC1407" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1408" class="blob-num js-line-number" data-line-number="1408"></td>
        <td id="LC1408" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1409" class="blob-num js-line-number" data-line-number="1409"></td>
        <td id="LC1409" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1410" class="blob-num js-line-number" data-line-number="1410"></td>
        <td id="LC1410" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1411" class="blob-num js-line-number" data-line-number="1411"></td>
        <td id="LC1411" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1412" class="blob-num js-line-number" data-line-number="1412"></td>
        <td id="LC1412" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1413" class="blob-num js-line-number" data-line-number="1413"></td>
        <td id="LC1413" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1414" class="blob-num js-line-number" data-line-number="1414"></td>
        <td id="LC1414" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">23</span>: <span class="pl-c"><span class="pl-c">//</span> was 44</span></td>
      </tr>
      <tr>
        <td id="L1415" class="blob-num js-line-number" data-line-number="1415"></td>
        <td id="LC1415" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> as mode 10 </span></td>
      </tr>
      <tr>
        <td id="L1416" class="blob-num js-line-number" data-line-number="1416"></td>
        <td id="LC1416" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*</span></td>
      </tr>
      <tr>
        <td id="L1417" class="blob-num js-line-number" data-line-number="1417"></td>
        <td id="LC1417" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1418" class="blob-num js-line-number" data-line-number="1418"></td>
        <td id="LC1418" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)){</td>
      </tr>
      <tr>
        <td id="L1419" class="blob-num js-line-number" data-line-number="1419"></td>
        <td id="LC1419" class="blob-code blob-code-inner js-file-line">	hcount++;</td>
      </tr>
      <tr>
        <td id="L1420" class="blob-num js-line-number" data-line-number="1420"></td>
        <td id="LC1420" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">7</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1421" class="blob-num js-line-number" data-line-number="1421"></td>
        <td id="LC1421" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1422" class="blob-num js-line-number" data-line-number="1422"></td>
        <td id="LC1422" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>((cvalue&gt;&gt;(<span class="pl-c1">8</span>+hcount))&amp;<span class="pl-c1">1</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L1423" class="blob-num js-line-number" data-line-number="1423"></td>
        <td id="LC1423" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1424" class="blob-num js-line-number" data-line-number="1424"></td>
        <td id="LC1424" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1425" class="blob-num js-line-number" data-line-number="1425"></td>
        <td id="LC1425" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1426" class="blob-num js-line-number" data-line-number="1426"></td>
        <td id="LC1426" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1427" class="blob-num js-line-number" data-line-number="1427"></td>
        <td id="LC1427" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1428" class="blob-num js-line-number" data-line-number="1428"></td>
        <td id="LC1428" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1429" class="blob-num js-line-number" data-line-number="1429"></td>
        <td id="LC1429" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1430" class="blob-num js-line-number" data-line-number="1430"></td>
        <td id="LC1430" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1431" class="blob-num js-line-number" data-line-number="1431"></td>
        <td id="LC1431" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1432" class="blob-num js-line-number" data-line-number="1432"></td>
        <td id="LC1432" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">24</span>: <span class="pl-c"><span class="pl-c">//</span> was 45</span></td>
      </tr>
      <tr>
        <td id="L1433" class="blob-num js-line-number" data-line-number="1433"></td>
        <td id="LC1433" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; entry into SR from CV - TM = no input bit = 3rd option of above...</span></td>
      </tr>
      <tr>
        <td id="L1434" class="blob-num js-line-number" data-line-number="1434"></td>
        <td id="LC1434" class="blob-code blob-code-inner js-file-line">      	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1435" class="blob-num js-line-number" data-line-number="1435"></td>
        <td id="LC1435" class="blob-code blob-code-inner js-file-line">      hcount++;</td>
      </tr>
      <tr>
        <td id="L1436" class="blob-num js-line-number" data-line-number="1436"></td>
        <td id="LC1436" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (hcount&gt;<span class="pl-c1">7</span>) hcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1437" class="blob-num js-line-number" data-line-number="1437"></td>
        <td id="LC1437" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1438" class="blob-num js-line-number" data-line-number="1438"></td>
        <td id="LC1438" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span>((cvalue&gt;&gt;(<span class="pl-c1">8</span>+hcount))&amp;<span class="pl-c1">1</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith); <span class="pl-c"><span class="pl-c">//</span> or we could &amp; with input bit - TO TEST!</span></td>
      </tr>
      <tr>
        <td id="L1439" class="blob-num js-line-number" data-line-number="1439"></td>
        <td id="LC1439" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1440" class="blob-num js-line-number" data-line-number="1440"></td>
        <td id="LC1440" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1441" class="blob-num js-line-number" data-line-number="1441"></td>
        <td id="LC1441" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)){</td>
      </tr>
      <tr>
        <td id="L1442" class="blob-num js-line-number" data-line-number="1442"></td>
        <td id="LC1442" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1443" class="blob-num js-line-number" data-line-number="1443"></td>
        <td id="LC1443" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1444" class="blob-num js-line-number" data-line-number="1444"></td>
        <td id="LC1444" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1445" class="blob-num js-line-number" data-line-number="1445"></td>
        <td id="LC1445" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1446" class="blob-num js-line-number" data-line-number="1446"></td>
        <td id="LC1446" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1447" class="blob-num js-line-number" data-line-number="1447"></td>
        <td id="LC1447" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1448" class="blob-num js-line-number" data-line-number="1448"></td>
        <td id="LC1448" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1449" class="blob-num js-line-number" data-line-number="1449"></td>
        <td id="LC1449" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">25</span>: <span class="pl-c"><span class="pl-c">//</span> was 48</span></td>
      </tr>
      <tr>
        <td id="L1450" class="blob-num js-line-number" data-line-number="1450"></td>
        <td id="LC1450" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>      	  extra mode in which pulse on is triggered by bitH but gated off by input bit or pulse</span></td>
      </tr>
      <tr>
        <td id="L1451" class="blob-num js-line-number" data-line-number="1451"></td>
        <td id="LC1451" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> use mode 13 as example here:::</span></td>
      </tr>
      <tr>
        <td id="L1452" class="blob-num js-line-number" data-line-number="1452"></td>
        <td id="LC1452" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1453" class="blob-num js-line-number" data-line-number="1453"></td>
        <td id="LC1453" class="blob-code blob-code-inner js-file-line">      	<span class="pl-c"><span class="pl-c">//</span> - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1454" class="blob-num js-line-number" data-line-number="1454"></td>
        <td id="LC1454" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1455" class="blob-num js-line-number" data-line-number="1455"></td>
        <td id="LC1455" class="blob-code blob-code-inner js-file-line">      probh=cvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1456" class="blob-num js-line-number" data-line-number="1456"></td>
        <td id="LC1456" class="blob-code blob-code-inner js-file-line">      probh=electroprob[probh];</td>
      </tr>
      <tr>
        <td id="L1457" class="blob-num js-line-number" data-line-number="1457"></td>
        <td id="LC1457" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1458" class="blob-num js-line-number" data-line-number="1458"></td>
        <td id="LC1458" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> new bits enter from shiftregleft - 0xff was looker[7]</span></td>
      </tr>
      <tr>
        <td id="L1459" class="blob-num js-line-number" data-line-number="1459"></td>
        <td id="LC1459" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1460" class="blob-num js-line-number" data-line-number="1460"></td>
        <td id="LC1460" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1461" class="blob-num js-line-number" data-line-number="1461"></td>
        <td id="LC1461" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1462" class="blob-num js-line-number" data-line-number="1462"></td>
        <td id="LC1462" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)) GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1463" class="blob-num js-line-number" data-line-number="1463"></td>
        <td id="LC1463" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1464" class="blob-num js-line-number" data-line-number="1464"></td>
        <td id="LC1464" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)) GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1465" class="blob-num js-line-number" data-line-number="1465"></td>
        <td id="LC1465" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1466" class="blob-num js-line-number" data-line-number="1466"></td>
        <td id="LC1466" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1467" class="blob-num js-line-number" data-line-number="1467"></td>
        <td id="LC1467" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">26</span>: <span class="pl-c"><span class="pl-c">//</span> was 50</span></td>
      </tr>
      <tr>
        <td id="L1468" class="blob-num js-line-number" data-line-number="1468"></td>
        <td id="LC1468" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1469" class="blob-num js-line-number" data-line-number="1469"></td>
        <td id="LC1469" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1470" class="blob-num js-line-number" data-line-number="1470"></td>
        <td id="LC1470" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)){</td>
      </tr>
      <tr>
        <td id="L1471" class="blob-num js-line-number" data-line-number="1471"></td>
        <td id="LC1471" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1472" class="blob-num js-line-number" data-line-number="1472"></td>
        <td id="LC1472" class="blob-code blob-code-inner js-file-line">      probh=cvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1473" class="blob-num js-line-number" data-line-number="1473"></td>
        <td id="LC1473" class="blob-code blob-code-inner js-file-line">      probh=electroprob[probh];</td>
      </tr>
      <tr>
        <td id="L1474" class="blob-num js-line-number" data-line-number="1474"></td>
        <td id="LC1474" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1475" class="blob-num js-line-number" data-line-number="1475"></td>
        <td id="LC1475" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> new bits enter from shiftregleft - 0xff was looker[7]</span></td>
      </tr>
      <tr>
        <td id="L1476" class="blob-num js-line-number" data-line-number="1476"></td>
        <td id="LC1476" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1477" class="blob-num js-line-number" data-line-number="1477"></td>
        <td id="LC1477" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1478" class="blob-num js-line-number" data-line-number="1478"></td>
        <td id="LC1478" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1479" class="blob-num js-line-number" data-line-number="1479"></td>
        <td id="LC1479" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1480" class="blob-num js-line-number" data-line-number="1480"></td>
        <td id="LC1480" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1481" class="blob-num js-line-number" data-line-number="1481"></td>
        <td id="LC1481" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1482" class="blob-num js-line-number" data-line-number="1482"></td>
        <td id="LC1482" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1483" class="blob-num js-line-number" data-line-number="1483"></td>
        <td id="LC1483" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1484" class="blob-num js-line-number" data-line-number="1484"></td>
        <td id="LC1484" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1485" class="blob-num js-line-number" data-line-number="1485"></td>
        <td id="LC1485" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">27</span>: <span class="pl-c"><span class="pl-c">//</span> was 52</span></td>
      </tr>
      <tr>
        <td id="L1486" class="blob-num js-line-number" data-line-number="1486"></td>
        <td id="LC1486" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>-&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt;&gt; Electronotes: CV selects which bits to set to 1 = chance of change</span></td>
      </tr>
      <tr>
        <td id="L1487" class="blob-num js-line-number" data-line-number="1487"></td>
        <td id="LC1487" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1488" class="blob-num js-line-number" data-line-number="1488"></td>
        <td id="LC1488" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>)){</td>
      </tr>
      <tr>
        <td id="L1489" class="blob-num js-line-number" data-line-number="1489"></td>
        <td id="LC1489" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out -</span></td>
      </tr>
      <tr>
        <td id="L1490" class="blob-num js-line-number" data-line-number="1490"></td>
        <td id="LC1490" class="blob-code blob-code-inner js-file-line">      probh=cvalue&gt;&gt;<span class="pl-c1">13</span>; <span class="pl-c"><span class="pl-c">//</span> 3 bits now for electroprob array</span></td>
      </tr>
      <tr>
        <td id="L1491" class="blob-num js-line-number" data-line-number="1491"></td>
        <td id="LC1491" class="blob-code blob-code-inner js-file-line">      probh=electroprob[probh];</td>
      </tr>
      <tr>
        <td id="L1492" class="blob-num js-line-number" data-line-number="1492"></td>
        <td id="LC1492" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1493" class="blob-num js-line-number" data-line-number="1493"></td>
        <td id="LC1493" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (((probh | shift_registerl) &amp; <span class="pl-c1">0xff</span> ) == <span class="pl-c1">0xff</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + ((shift_registerl&gt;&gt;SRlengthl) &amp; <span class="pl-c1">0x01</span>); <span class="pl-c"><span class="pl-c">//</span> new bits enter from shiftregleft - 0xff was looker[7]</span></td>
      </tr>
      <tr>
        <td id="L1494" class="blob-num js-line-number" data-line-number="1494"></td>
        <td id="LC1494" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1495" class="blob-num js-line-number" data-line-number="1495"></td>
        <td id="LC1495" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1496" class="blob-num js-line-number" data-line-number="1496"></td>
        <td id="LC1496" class="blob-code blob-code-inner js-file-line">      </td>
      </tr>
      <tr>
        <td id="L1497" class="blob-num js-line-number" data-line-number="1497"></td>
        <td id="LC1497" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1498" class="blob-num js-line-number" data-line-number="1498"></td>
        <td id="LC1498" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1499" class="blob-num js-line-number" data-line-number="1499"></td>
        <td id="LC1499" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1500" class="blob-num js-line-number" data-line-number="1500"></td>
        <td id="LC1500" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1501" class="blob-num js-line-number" data-line-number="1501"></td>
        <td id="LC1501" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1502" class="blob-num js-line-number" data-line-number="1502"></td>
        <td id="LC1502" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1503" class="blob-num js-line-number" data-line-number="1503"></td>
        <td id="LC1503" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">28</span>: <span class="pl-c"><span class="pl-c">//</span> was 53</span></td>
      </tr>
      <tr>
        <td id="L1504" class="blob-num js-line-number" data-line-number="1504"></td>
        <td id="LC1504" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits</span></td>
      </tr>
      <tr>
        <td id="L1505" class="blob-num js-line-number" data-line-number="1505"></td>
        <td id="LC1505" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> change and Re_test this - TESTED/working</span></td>
      </tr>
      <tr>
        <td id="L1506" class="blob-num js-line-number" data-line-number="1506"></td>
        <td id="LC1506" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> loop bith back in XOR at certain point?</span></td>
      </tr>
      <tr>
        <td id="L1507" class="blob-num js-line-number" data-line-number="1507"></td>
        <td id="LC1507" class="blob-code blob-code-inner js-file-line">	bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out</span></td>
      </tr>
      <tr>
        <td id="L1508" class="blob-num js-line-number" data-line-number="1508"></td>
        <td id="LC1508" class="blob-code blob-code-inner js-file-line">	shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1509" class="blob-num js-line-number" data-line-number="1509"></td>
        <td id="LC1509" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span> do the loop back in</span></td>
      </tr>
      <tr>
        <td id="L1510" class="blob-num js-line-number" data-line-number="1510"></td>
        <td id="LC1510" class="blob-code blob-code-inner js-file-line">	hcount=cvalue&gt;&gt;<span class="pl-c1">11</span>; <span class="pl-c"><span class="pl-c">//</span> 5 bits - or: hcount=(cvalue&gt;&gt;11)%(SRlengthh+1);</span></td>
      </tr>
      <tr>
        <td id="L1511" class="blob-num js-line-number" data-line-number="1511"></td>
        <td id="LC1511" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) shift_registerh ^= (<span class="pl-c1">1</span>&lt;&lt;hcount);<span class="pl-c"><span class="pl-c">//</span> set the xth bit</span></td>
      </tr>
      <tr>
        <td id="L1512" class="blob-num js-line-number" data-line-number="1512"></td>
        <td id="LC1512" class="blob-code blob-code-inner js-file-line">	shift_registerh ^= (!(GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>));</td>
      </tr>
      <tr>
        <td id="L1513" class="blob-num js-line-number" data-line-number="1513"></td>
        <td id="LC1513" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1514" class="blob-num js-line-number" data-line-number="1514"></td>
        <td id="LC1514" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1515" class="blob-num js-line-number" data-line-number="1515"></td>
        <td id="LC1515" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1516" class="blob-num js-line-number" data-line-number="1516"></td>
        <td id="LC1516" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1517" class="blob-num js-line-number" data-line-number="1517"></td>
        <td id="LC1517" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1518" class="blob-num js-line-number" data-line-number="1518"></td>
        <td id="LC1518" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1519" class="blob-num js-line-number" data-line-number="1519"></td>
        <td id="LC1519" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1520" class="blob-num js-line-number" data-line-number="1520"></td>
        <td id="LC1520" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">29</span>: <span class="pl-c"><span class="pl-c">//</span> was 56</span></td>
      </tr>
      <tr>
        <td id="L1521" class="blob-num js-line-number" data-line-number="1521"></td>
        <td id="LC1521" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1522" class="blob-num js-line-number" data-line-number="1522"></td>
        <td id="LC1522" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> can use CV as length of either SR = here is regularSR</span></td>
      </tr>
      <tr>
        <td id="L1523" class="blob-num js-line-number" data-line-number="1523"></td>
        <td id="LC1523" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>       - TESTED/working</span></td>
      </tr>
      <tr>
        <td id="L1524" class="blob-num js-line-number" data-line-number="1524"></td>
        <td id="LC1524" class="blob-code blob-code-inner js-file-line">      SRlengthh=(cvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1525" class="blob-num js-line-number" data-line-number="1525"></td>
        <td id="LC1525" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthh&lt;<span class="pl-c1">4</span>) SRlengthh=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1526" class="blob-num js-line-number" data-line-number="1526"></td>
        <td id="LC1526" class="blob-code blob-code-inner js-file-line">      lengthbith=(<span class="pl-c1">1</span>&lt;&lt;(SRlengthh/<span class="pl-c1">2</span>));</td>
      </tr>
      <tr>
        <td id="L1527" class="blob-num js-line-number" data-line-number="1527"></td>
        <td id="LC1527" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1528" class="blob-num js-line-number" data-line-number="1528"></td>
        <td id="LC1528" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L1529" class="blob-num js-line-number" data-line-number="1529"></td>
        <td id="LC1529" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][0])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][1])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][2])) ^ (shift_registerh &gt;&gt; (lfsr_taps[SRlengthh][3]))) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1530" class="blob-num js-line-number" data-line-number="1530"></td>
        <td id="LC1530" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; <span class="pl-c1">31</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">29</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">25</span>) ^ (shift_registerx &gt;&gt; <span class="pl-c1">24</span>)) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1531" class="blob-num js-line-number" data-line-number="1531"></td>
        <td id="LC1531" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L1532" class="blob-num js-line-number" data-line-number="1532"></td>
        <td id="LC1532" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1533" class="blob-num js-line-number" data-line-number="1533"></td>
        <td id="LC1533" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L1534" class="blob-num js-line-number" data-line-number="1534"></td>
        <td id="LC1534" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L1535" class="blob-num js-line-number" data-line-number="1535"></td>
        <td id="LC1535" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1536" class="blob-num js-line-number" data-line-number="1536"></td>
        <td id="LC1536" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L1537" class="blob-num js-line-number" data-line-number="1537"></td>
        <td id="LC1537" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1538" class="blob-num js-line-number" data-line-number="1538"></td>
        <td id="LC1538" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1539" class="blob-num js-line-number" data-line-number="1539"></td>
        <td id="LC1539" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1540" class="blob-num js-line-number" data-line-number="1540"></td>
        <td id="LC1540" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1541" class="blob-num js-line-number" data-line-number="1541"></td>
        <td id="LC1541" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1542" class="blob-num js-line-number" data-line-number="1542"></td>
        <td id="LC1542" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L1543" class="blob-num js-line-number" data-line-number="1543"></td>
        <td id="LC1543" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1544" class="blob-num js-line-number" data-line-number="1544"></td>
        <td id="LC1544" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1545" class="blob-num js-line-number" data-line-number="1545"></td>
        <td id="LC1545" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">30</span>: <span class="pl-c"><span class="pl-c">//</span> was 57</span></td>
      </tr>
      <tr>
        <td id="L1546" class="blob-num js-line-number" data-line-number="1546"></td>
        <td id="LC1546" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!</span></td>
      </tr>
      <tr>
        <td id="L1547" class="blob-num js-line-number" data-line-number="1547"></td>
        <td id="LC1547" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> can use CV as length of either SR = here is SRx</span></td>
      </tr>
      <tr>
        <td id="L1548" class="blob-num js-line-number" data-line-number="1548"></td>
        <td id="LC1548" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span>       - TESTED/working but not so satisfying for cvalue use</span></td>
      </tr>
      <tr>
        <td id="L1549" class="blob-num js-line-number" data-line-number="1549"></td>
        <td id="LC1549" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1550" class="blob-num js-line-number" data-line-number="1550"></td>
        <td id="LC1550" class="blob-code blob-code-inner js-file-line">      SRlengthx=(cvalue&gt;&gt;<span class="pl-c1">11</span>);</td>
      </tr>
      <tr>
        <td id="L1551" class="blob-num js-line-number" data-line-number="1551"></td>
        <td id="LC1551" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (SRlengthx&lt;<span class="pl-c1">4</span>) SRlengthx=<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1552" class="blob-num js-line-number" data-line-number="1552"></td>
        <td id="LC1552" class="blob-code blob-code-inner js-file-line">	</td>
      </tr>
      <tr>
        <td id="L1553" class="blob-num js-line-number" data-line-number="1553"></td>
        <td id="LC1553" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (shift_registerx==<span class="pl-c1">0</span>) shift_registerx=<span class="pl-c1">0xff</span>; <span class="pl-c"><span class="pl-c">//</span> catch it!</span></td>
      </tr>
      <tr>
        <td id="L1554" class="blob-num js-line-number" data-line-number="1554"></td>
        <td id="LC1554" class="blob-code blob-code-inner js-file-line">	bith= ((shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">0</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">1</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">2</span>])) ^ (shift_registerx &gt;&gt; (lfsr_taps[SRlengthx][<span class="pl-c1">3</span>]))) &amp; <span class="pl-c1">1u</span>; <span class="pl-c"><span class="pl-c">//</span> 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1555" class="blob-num js-line-number" data-line-number="1555"></td>
        <td id="LC1555" class="blob-code blob-code-inner js-file-line">	<span class="pl-c"><span class="pl-c">//</span>	bith= ((shift_registerx &gt;&gt; 31) ^ (shift_registerx &gt;&gt; 29) ^ (shift_registerx &gt;&gt; 25) ^ (shift_registerx &gt;&gt; 24)) &amp; 1u; // 32 is 31, 29, 25, 24</span></td>
      </tr>
      <tr>
        <td id="L1556" class="blob-num js-line-number" data-line-number="1556"></td>
        <td id="LC1556" class="blob-code blob-code-inner js-file-line">	shift_registerx = (shift_registerx&lt;&lt;<span class="pl-c1">1</span>) + bith; <span class="pl-c"><span class="pl-c">//</span> could or with incoming as we don&#39;t use this TESTY: shift_registerx = (shift_registerx&lt;&lt;1) + (bith | !(GPIOB-&gt;IDR &amp; 0x0400)); </span></td>
      </tr>
      <tr>
        <td id="L1557" class="blob-num js-line-number" data-line-number="1557"></td>
        <td id="LC1557" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1558" class="blob-num js-line-number" data-line-number="1558"></td>
        <td id="LC1558" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">if</span> (bith){ <span class="pl-c"><span class="pl-c">//</span> calculate and output new bith with case 3 Turing Machine:</span></td>
      </tr>
      <tr>
        <td id="L1559" class="blob-num js-line-number" data-line-number="1559"></td>
        <td id="LC1559" class="blob-code blob-code-inner js-file-line">	  bith = (shift_registerh&gt;&gt;SRlengthh) &amp; <span class="pl-c1">0x01</span>; <span class="pl-c"><span class="pl-c">//</span> bit which would be shifted out </span></td>
      </tr>
      <tr>
        <td id="L1560" class="blob-num js-line-number" data-line-number="1560"></td>
        <td id="LC1560" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + bith;</td>
      </tr>
      <tr>
        <td id="L1561" class="blob-num js-line-number" data-line-number="1561"></td>
        <td id="LC1561" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;<span class="pl-c1">1</span>) + (!bith);</td>
      </tr>
      <tr>
        <td id="L1562" class="blob-num js-line-number" data-line-number="1562"></td>
        <td id="LC1562" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1563" class="blob-num js-line-number" data-line-number="1563"></td>
        <td id="LC1563" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1564" class="blob-num js-line-number" data-line-number="1564"></td>
        <td id="LC1564" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1565" class="blob-num js-line-number" data-line-number="1565"></td>
        <td id="LC1565" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others</span></td>
      </tr>
      <tr>
        <td id="L1566" class="blob-num js-line-number" data-line-number="1566"></td>
        <td id="LC1566" class="blob-code blob-code-inner js-file-line">	  <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;</td>
      </tr>
      <tr>
        <td id="L1567" class="blob-num js-line-number" data-line-number="1567"></td>
        <td id="LC1567" class="blob-code blob-code-inner js-file-line">	}</td>
      </tr>
      <tr>
        <td id="L1568" class="blob-num js-line-number" data-line-number="1568"></td>
        <td id="LC1568" class="blob-code blob-code-inner js-file-line">	<span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1569" class="blob-num js-line-number" data-line-number="1569"></td>
        <td id="LC1569" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1570" class="blob-num js-line-number" data-line-number="1570"></td>
        <td id="LC1570" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">case</span> <span class="pl-c1">31</span>: <span class="pl-c"><span class="pl-c">//</span> was 58 -  change the shifting amount - sort of works but not a great range and we need to take care of length</span></td>
      </tr>
      <tr>
        <td id="L1571" class="blob-num js-line-number" data-line-number="1571"></td>
        <td id="LC1571" class="blob-code blob-code-inner js-file-line">      shifter=(cvalue&gt;&gt;<span class="pl-c1">11</span>)%(SRlengthh+<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1572" class="blob-num js-line-number" data-line-number="1572"></td>
        <td id="LC1572" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shifter==<span class="pl-c1">0</span>) shifter=<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1573" class="blob-num js-line-number" data-line-number="1573"></td>
        <td id="LC1573" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> TM here</span></td>
      </tr>
      <tr>
        <td id="L1574" class="blob-num js-line-number" data-line-number="1574"></td>
        <td id="LC1574" class="blob-code blob-code-inner js-file-line">      bith = (shift_registerh&gt;&gt;(SRlengthh-(shifter-<span class="pl-c1">1</span>))) &amp; (shifter); <span class="pl-c"><span class="pl-c">//</span> bits which would be shifted out  // 1 for length of 31</span></td>
      </tr>
      <tr>
        <td id="L1575" class="blob-num js-line-number" data-line-number="1575"></td>
        <td id="LC1575" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (GPIOB-&gt;<span class="pl-smi">IDR</span> &amp; <span class="pl-c1">0x0400</span>) shift_registerh = (shift_registerh&lt;&lt;shifter) + bith;</td>
      </tr>
      <tr>
        <td id="L1576" class="blob-num js-line-number" data-line-number="1576"></td>
        <td id="LC1576" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> shift_registerh = (shift_registerh&lt;&lt;shifter) + (~bith);</td>
      </tr>
      <tr>
        <td id="L1577" class="blob-num js-line-number" data-line-number="1577"></td>
        <td id="LC1577" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1578" class="blob-num js-line-number" data-line-number="1578"></td>
        <td id="LC1578" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0010000000000000</span>;  <span class="pl-c"><span class="pl-c">//</span> clear PC13 else write one</span></td>
      </tr>
      <tr>
        <td id="L1579" class="blob-num js-line-number" data-line-number="1579"></td>
        <td id="LC1579" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0010000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1580" class="blob-num js-line-number" data-line-number="1580"></td>
        <td id="LC1580" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (shift_registerh &amp; lengthbith) GPIOC-&gt;<span class="pl-smi">BRR</span> = <span class="pl-c1">0b0100000000000000</span>; </td>
      </tr>
      <tr>
        <td id="L1581" class="blob-num js-line-number" data-line-number="1581"></td>
        <td id="LC1581" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">else</span> GPIOC-&gt;<span class="pl-smi">BSRR</span> = <span class="pl-c1">0b0100000000000000</span>;  </td>
      </tr>
      <tr>
        <td id="L1582" class="blob-num js-line-number" data-line-number="1582"></td>
        <td id="LC1582" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1583" class="blob-num js-line-number" data-line-number="1583"></td>
        <td id="LC1583" class="blob-code blob-code-inner js-file-line">    }       <span class="pl-c"><span class="pl-c">//</span>/ end of HF modes</span></td>
      </tr>
      <tr>
        <td id="L1584" class="blob-num js-line-number" data-line-number="1584"></td>
        <td id="LC1584" class="blob-code blob-code-inner js-file-line">  }  </td>
      </tr>
      <tr>
        <td id="L1585" class="blob-num js-line-number" data-line-number="1585"></td>
        <td id="LC1585" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1586" class="blob-num js-line-number" data-line-number="1586"></td>
        <td id="LC1586" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
</table>

  <details class="details-reset details-overlay BlobToolbar position-absolute js-file-line-actions dropdown d-none" aria-hidden="true">
    <summary class="btn-octicon ml-0 px-2 p-0 bg-white border border-gray-dark rounded-1" aria-label="Inline file action toolbar">
      <svg class="octicon octicon-kebab-horizontal" viewBox="0 0 13 16" version="1.1" width="13" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M1.5 9a1.5 1.5 0 100-3 1.5 1.5 0 000 3zm5 0a1.5 1.5 0 100-3 1.5 1.5 0 000 3zM13 7.5a1.5 1.5 0 11-3 0 1.5 1.5 0 013 0z"></path></svg>
    </summary>
    <details-menu>
      <ul class="BlobToolbar-dropdown dropdown-menu dropdown-menu-se mt-2" style="width:185px">
        <li>
          <clipboard-copy role="menuitem" class="dropdown-item" id="js-copy-lines" style="cursor:pointer;">
            Copy lines
          </clipboard-copy>
        </li>
        <li>
          <clipboard-copy role="menuitem" class="dropdown-item" id="js-copy-permalink" style="cursor:pointer;">
            Copy permalink
          </clipboard-copy>
        </li>
        <li><a class="dropdown-item js-update-url-with-hash" id="js-view-git-blame" role="menuitem" href="/microresearch/allcolours/blame/cbbae983cfc43bc6e5ab6ab247f026e9ba4ef81c/software/STM32F103/src/stm32f10x_it.c">View git blame</a></li>
          <li><a class="dropdown-item" id="js-new-issue" role="menuitem" href="/microresearch/allcolours/issues/new">Reference in new issue</a></li>
      </ul>
    </details-menu>
  </details>

  </div>

    </div>

  

  <details class="details-reset details-overlay details-overlay-dark">
    <summary data-hotkey="l" aria-label="Jump to line"></summary>
    <details-dialog class="Box Box--overlay d-flex flex-column anim-fade-in fast linejump" aria-label="Jump to line">
      <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="js-jump-to-line-form Box-body d-flex" action="" accept-charset="UTF-8" method="get">
        <input class="form-control flex-auto mr-3 linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
        <button type="submit" class="btn" data-close-dialog>Go</button>
</form>    </details-dialog>
  </details>



  </div>
</div>

    </main>
  </div>
  

  </div>

        
<div class="footer container-lg width-full p-responsive" role="contentinfo">
  <div class="position-relative d-flex flex-row-reverse flex-lg-row flex-wrap flex-lg-nowrap flex-justify-center flex-lg-justify-between pt-6 pb-2 mt-6 f6 text-gray border-top border-gray-light ">
    <ul class="list-style-none d-flex flex-wrap col-12 col-lg-5 flex-justify-center flex-lg-justify-between mb-2 mb-lg-0">
      <li class="mr-3 mr-lg-0">&copy; 2020 GitHub, Inc.</li>
        <li class="mr-3 mr-lg-0"><a data-ga-click="Footer, go to terms, text:terms" href="https://github.com/site/terms">Terms</a></li>
        <li class="mr-3 mr-lg-0"><a data-ga-click="Footer, go to privacy, text:privacy" href="https://github.com/site/privacy">Privacy</a></li>
        <li class="mr-3 mr-lg-0"><a data-ga-click="Footer, go to security, text:security" href="https://github.com/security">Security</a></li>
        <li class="mr-3 mr-lg-0"><a href="https://githubstatus.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
        <li><a data-ga-click="Footer, go to help, text:help" href="https://help.github.com">Help</a></li>

    </ul>

    <a aria-label="Homepage" title="GitHub" class="footer-octicon d-none d-lg-block mx-lg-4" href="https://github.com">
      <svg height="24" class="octicon octicon-mark-github" viewBox="0 0 16 16" version="1.1" width="24" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0016 8c0-4.42-3.58-8-8-8z"></path></svg>
</a>
   <ul class="list-style-none d-flex flex-wrap col-12 col-lg-5 flex-justify-center flex-lg-justify-between mb-2 mb-lg-0">
        <li class="mr-3 mr-lg-0"><a data-ga-click="Footer, go to contact, text:contact" href="https://github.com/contact">Contact GitHub</a></li>
        <li class="mr-3 mr-lg-0"><a href="https://github.com/pricing" data-ga-click="Footer, go to Pricing, text:Pricing">Pricing</a></li>
      <li class="mr-3 mr-lg-0"><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li class="mr-3 mr-lg-0"><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
        <li class="mr-3 mr-lg-0"><a href="https://github.blog" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a data-ga-click="Footer, go to about, text:about" href="https://github.com/about">About</a></li>
    </ul>
  </div>
  <div class="d-flex flex-justify-center pb-6">
    <span class="f6 text-gray-light"></span>
  </div>
</div>



  <div id="ajax-error-message" class="ajax-error-message flash flash-error">
    <svg class="octicon octicon-alert" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.893 1.5c-.183-.31-.52-.5-.887-.5s-.703.19-.886.5L.138 13.499a.98.98 0 000 1.001c.193.31.53.501.886.501h13.964c.367 0 .704-.19.877-.5a1.03 1.03 0 00.01-1.002L8.893 1.5zm.133 11.497H6.987v-2.003h2.039v2.003zm0-3.004H6.987V5.987h2.039v4.006z"></path></svg>
    <button type="button" class="flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
      <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48L7.48 8z"></path></svg>
    </button>
    You can’t perform that action at this time.
  </div>


    <script crossorigin="anonymous" async="async" integrity="sha512-WcQmT2vhcClFVOaaAJV/M+HqsJ2Gq/myvl6F3gCVBxykazXTs+i5fvxncSXwyG1CSfcrqmLFw/R/bmFYzprX2A==" type="application/javascript" id="js-conditional-compat" data-src="https://github.githubassets.com/assets/compat-bootstrap-59c4264f.js"></script>
    <script crossorigin="anonymous" integrity="sha512-qRIR9sJtW+F0sy3P1EuUI81C+jzXTa54zUOyTmKhz64cc/Wj2XT1nnh23ZjWj1CFf8tO9LOn49s79ilOILcGkA==" type="application/javascript" src="https://github.githubassets.com/assets/environment-bootstrap-a91211f6.js"></script>
      <script crossorigin="anonymous" async="async" integrity="sha512-qUt0W3Q++EcTV/FjWCH4pkCuFrwLmBaxXaem85oHWp5D40Jb6WozJdUpeKQgU3fguUZ7cqxD1gpjU6f4u3ScKg==" type="application/javascript" src="https://github.githubassets.com/assets/vendor-a94b745b.js"></script>
      <script crossorigin="anonymous" async="async" integrity="sha512-rutDIkXq5R26gtjTr30nd7ub41bvcB2crxo9FQjYjSDQdqlhgGw8iZ4BikE/zqUFACXy1bTHXTTEaIYHay7L/A==" type="application/javascript" src="https://github.githubassets.com/assets/frameworks-aeeb4322.js"></script>
    
    <script crossorigin="anonymous" async="async" integrity="sha512-2KyONegToI+AWMnMdypgMW87N1EH3NPx62wQyX/GA8ZRXwB3YAk3uDxvSnH+aMG1dCtJMUxGKwjHf92Kn/liBw==" type="application/javascript" src="https://github.githubassets.com/assets/github-bootstrap-d8ac8e35.js"></script>
    
    
    
  <div class="js-stale-session-flash flash flash-warn flash-banner" hidden
    >
    <svg class="octicon octicon-alert" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.893 1.5c-.183-.31-.52-.5-.887-.5s-.703.19-.886.5L.138 13.499a.98.98 0 000 1.001c.193.31.53.501.886.501h13.964c.367 0 .704-.19.877-.5a1.03 1.03 0 00.01-1.002L8.893 1.5zm.133 11.497H6.987v-2.003h2.039v2.003zm0-3.004H6.987V5.987h2.039v4.006z"></path></svg>
    <span class="js-stale-session-flash-signed-in" hidden>You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
    <span class="js-stale-session-flash-signed-out" hidden>You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
  </div>
  <template id="site-details-dialog">
  <details class="details-reset details-overlay details-overlay-dark lh-default text-gray-dark hx_rsm" open>
    <summary role="button" aria-label="Close dialog"></summary>
    <details-dialog class="Box Box--overlay d-flex flex-column anim-fade-in fast hx_rsm-dialog hx_rsm-modal">
      <button class="Box-btn-octicon m-0 btn-octicon position-absolute right-0 top-0" type="button" aria-label="Close dialog" data-close-dialog>
        <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48L7.48 8z"></path></svg>
      </button>
      <div class="octocat-spinner my-6 js-details-dialog-spinner"></div>
    </details-dialog>
  </details>
</template>

  <div class="Popover js-hovercard-content position-absolute" style="display: none; outline: none;" tabindex="0">
  <div class="Popover-message Popover-message--bottom-left Popover-message--large Box box-shadow-large" style="width:360px;">
  </div>
</div>

  <div aria-live="polite" class="js-global-screen-reader-notice sr-only"></div>

  </body>
</html>

