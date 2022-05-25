 void SetStyle(TH1* h1,int Color);
 void EF_Calculator_smallR(const char* fname, int Ptlow, int Pthigh){

        //Open the file and retrieve the general list of the histograms
        TFile*f1 = TFile::Open(fname);
        AliEmcalList* ali;
        f1->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_MCprod_GenDet_histos",ali);
        //Retrieving the DelatR histograms (2D) - Detector level
        TH2D* hDR005 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R005_0")); TH2D* hDR010 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R010_0"));
        TH2D* hDR015 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R015_0")); TH2D* hDR020 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R020_0"));
        TH2D* hDR025 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R025_0")); TH2D* hDR030 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R030_0"));
        TH2D* hDR035 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R035_0"));

        // Generator level
        TH2D* hDR005_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R005_gen_0")); TH2D* hDR010_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R010_gen_0"));
        TH2D* hDR015_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R015_gen_0")); TH2D* hDR020_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R020_gen_0"));
        TH2D* hDR025_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R025_gen_0")); TH2D* hDR030_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R030_gen_0"));
        TH2D* hDR035_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R035_gen_0"));

        //Retrieving the Dpt histograms (2D)- Detector level
        TH2D* hDptR005 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R005_0")); TH2D* hDptR010 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R010_0"));
        TH2D* hDptR015 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R015_0")); TH2D* hDptR020 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R020_0"));
        TH2D* hDptR025 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R025_0")); TH2D* hDptR030 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R030_0"));
        TH2D* hDptR035 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R035_0"));
        // Generator level
        TH2D* hDptR005_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R005_gen_0")); TH2D* hDptR010_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R010_gen_0"));
        TH2D* hDptR015_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R015_gen_0")); TH2D* hDptR020_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R020_gen_0"));
        TH2D* hDptR025_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R025_gen_0")); TH2D* hDptR030_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R030_gen_0"));
        TH2D* hDptR035_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R035_gen_0"));


       int Ptlow_bin =hDR010->GetXaxis()->FindBin(Ptlow);
       int Pthigh_bin = hDR010->GetXaxis()->FindBin(Pthigh);

        //Retrieving the matched jet spectra- Detector level
        TH1D* hJetPtMatched_R005 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R005_0")); TH1D* hJetPtMatched_R010 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R010_0"));
        TH1D* hJetPtMatched_R015 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R015_0")); TH1D* hJetPtMatched_R020 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R020_0")); 
        TH1D* hJetPtMatched_R025 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R025_0")); TH1D* hJetPtMatched_R030 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R030_0"));
        TH1D* hJetPtMatched_R035 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R035_0")); TH1D* hJetPtMatched_R040 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R040_0"));

        TH1D* hJetEtaMatched_R005 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R005_0")); TH1D* hJetEtaMatched_R010 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R010_0"));
        TH1D* hJetEtaMatched_R015 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R015_0")); TH1D* hJetEtaMatched_R020 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R020_0"));
        TH1D* hJetEtaMatched_R025 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R025_0")); TH1D* hJetEtaMatched_R030 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R030_0"));
        TH1D* hJetEtaMatched_R035 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R035_0")); TH1D* hJetEtaMatched_R040 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R040_0"));
        //Generator level
        TH1D* hJetPtMatched_R005_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R005_gen_0")); TH1D* hJetPtMatched_R010_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R010_gen_0"));
        TH1D* hJetPtMatched_R015_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R015_gen_0")); TH1D* hJetPtMatched_R020_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R020_gen_0")); 
        TH1D* hJetPtMatched_R025_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R025_gen_0")); TH1D* hJetPtMatched_R030_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R030_gen_0"));
        TH1D* hJetPtMatched_R035_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R035_gen_0")); TH1D* hJetPtMatched_R040_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R040_gen_0"));

        TH1D* hJetEtaMatched_R005_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R005_gen_0")); TH1D* hJetEtaMatched_R010_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R010_gen_0"));
        TH1D* hJetEtaMatched_R015_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R015_gen_0")); TH1D* hJetEtaMatched_R020_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R020_gen_0"));
        TH1D* hJetEtaMatched_R025_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R025_gen_0")); TH1D* hJetEtaMatched_R030_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R030_gen_0"));
        TH1D* hJetEtaMatched_R035_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R035_gen_0")); TH1D* hJetEtaMatched_R040_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R040_gen_0"));


        //Retrieving the collection for each jet container- Detector level
        THashList*jetR005 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR005_tracks_pT0150_E_scheme"));        
        THashList*jetR010 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR010_tracks_pT0150_E_scheme"));
        THashList*jetR015 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR015_tracks_pT0150_E_scheme"));
        THashList*jetR020 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR020_tracks_pT0150_E_scheme"));
        THashList*jetR025 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR025_tracks_pT0150_E_scheme"));
        THashList*jetR030 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR030_tracks_pT0150_E_scheme"));
        THashList*jetR035 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR035_tracks_pT0150_E_scheme"));
        THashList*jetR040 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR040_tracks_pT0150_E_scheme"));

        //Generator level
        THashList*jetR005_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR005_mcparticles_pT0150_E_scheme"));
        THashList*jetR010_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR010_mcparticles_pT0150_E_scheme"));
        THashList*jetR015_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR015_mcparticles_pT0150_E_scheme"));
        THashList*jetR020_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR020_mcparticles_pT0150_E_scheme"));
        THashList*jetR025_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR025_mcparticles_pT0150_E_scheme"));
        THashList*jetR030_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR030_mcparticles_pT0150_E_scheme"));
        THashList*jetR035_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR035_mcparticles_pT0150_E_scheme"));
        THashList*jetR040_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR040_mcparticles_pT0150_E_scheme"));


        //Retrieving some basic histograms (pt, phi, eta) for each jet container
                                //Detector level
        //Jet R=0.05
        TH1D*hJetPt_R005 = static_cast<TH1D*>(jetR005->FindObject("histJetPt_0"));// hJetPt_R005->Sumw2();
        TH1D*hJetEta_R005 = static_cast<TH1D*>(jetR005->FindObject("histJetEta_0"));

        //Jet R=0.1
        TH1D*hJetPt_R01 = static_cast<TH1D*>(jetR010->FindObject("histJetPt_0"));// hJetPt_R01->Sumw2();
        TH1D*hJetEta_R01 = static_cast<TH1D*>(jetR010->FindObject("histJetEta_0"));

        //Jet R=0.15
        TH1D*hJetPt_R015 = static_cast<TH1D*>(jetR015->FindObject("histJetPt_0"));// hJetPt_R015->Sumw2();
        TH1D*hJetEta_R015 = static_cast<TH1D*>(jetR015->FindObject("histJetEta_0"));

        //Jet R=0.2
        TH1D*hJetPt_R02 = static_cast<TH1D*>(jetR020->FindObject("histJetPt_0"));// hJetPt_R02->Sumw2();
        TH1D*hJetEta_R02 = static_cast<TH1D*>(jetR020->FindObject("histJetEta_0"));

        //Jet R=0.25
        TH1D*hJetPt_R025 = static_cast<TH1D*>(jetR025->FindObject("histJetPt_0"));// hJetPt_R025->Sumw2();
        TH1D*hJetEta_R025 = static_cast<TH1D*>(jetR025->FindObject("histJetEta_0"));

        //Jet R=0.3
        TH1D*hJetPt_R03 = static_cast<TH1D*>(jetR030->FindObject("histJetPt_0"));// hJetPt_R03->Sumw2();
        TH1D*hJetEta_R03 = static_cast<TH1D*>(jetR030->FindObject("histJetEta_0"));

        //Jet R=0.35
        TH1D*hJetPt_R035 = static_cast<TH1D*>(jetR035->FindObject("histJetPt_0"));// hJetPt_R035->Sumw2();
        TH1D*hJetEta_R035 = static_cast<TH1D*>(jetR035->FindObject("histJetEta_0"));

        //Jet R=0.4
        TH1D*hJetPt_R04 = static_cast<TH1D*>(jetR040->FindObject("histJetPt_0"));// hJetPt_R04->Sumw2();
        TH1D*hJetEta_R04 = static_cast<TH1D*>(jetR040->FindObject("histJetEta_0"));

                        //Truth level
       //Jet R=0.05
        TH1D*hJetPt_R005_gen = static_cast<TH1D*>(jetR005_gen->FindObject("histJetPt_0"));// hJetPt_R005_gen->Sumw2();
        TH1D*hJetEta_R005_gen = static_cast<TH1D*>(jetR005_gen->FindObject("histJetEta_0"));

        //Jet R=0.1
        TH1D*hJetPt_R01_gen = static_cast<TH1D*>(jetR010_gen->FindObject("histJetPt_0")); //hJetPt_R01_gen->Sumw2();
        TH1D*hJetEta_R01_gen = static_cast<TH1D*>(jetR010_gen->FindObject("histJetEta_0"));

        //Jet R=0.15
        TH1D*hJetPt_R015_gen = static_cast<TH1D*>(jetR015_gen->FindObject("histJetPt_0")); //hJetPt_R015_gen->Sumw2();
        TH1D*hJetEta_R015_gen = static_cast<TH1D*>(jetR015_gen->FindObject("histJetEta_0"));

        //Jet R=0.2
        TH1D*hJetPt_R02_gen = static_cast<TH1D*>(jetR020_gen->FindObject("histJetPt_0")); //hJetPt_R02_gen->Sumw2();
        TH1D*hJetEta_R02_gen = static_cast<TH1D*>(jetR020_gen->FindObject("histJetEta_0"));

        //Jet R=0.25
        TH1D*hJetPt_R025_gen = static_cast<TH1D*>(jetR025_gen->FindObject("histJetPt_0"));// hJetPt_R025_gen->Sumw2();
        TH1D*hJetEta_R025_gen = static_cast<TH1D*>(jetR025_gen->FindObject("histJetEta_0"));

        //Jet R=0.3
        TH1D*hJetPt_R03_gen = static_cast<TH1D*>(jetR030_gen->FindObject("histJetPt_0"));// hJetPt_R03_gen->Sumw2();
        TH1D*hJetEta_R03_gen = static_cast<TH1D*>(jetR030_gen->FindObject("histJetEta_0"));

        //Jet R=0.35
        TH1D*hJetPt_R035_gen = static_cast<TH1D*>(jetR035_gen->FindObject("histJetPt_0"));// hJetPt_R035_gen->Sumw2();
        TH1D*hJetEta_R035_gen = static_cast<TH1D*>(jetR035_gen->FindObject("histJetEta_0"));

        //Jet R=0.4
        TH1D*hJetPt_R04_gen = static_cast<TH1D*>(jetR040_gen->FindObject("histJetPt_0")); //hJetPt_R04_gen->Sumw2();
        TH1D*hJetEta_R04_gen = static_cast<TH1D*>(jetR040_gen->FindObject("histJetEta_0"));

//------------------------Histogram manipulation will happen here---------------------
          gStyle->SetOptStat(0);
          gStyle->SetTitleFont(42);
          gStyle->SetTitleSize(0.05);
          gStyle->SetTitleSize(0.04,"Y");
          gStyle->SetTitleSize(0.04,"X");
          gStyle->SetTitleOffset(0.9,"xy");
          gStyle->SetLegendTextSize(0.025);
          gStyle->SetTitleXOffset(.9);
          gStyle->SetTitleYOffset(.9);
                                //Detector level
        //Jet pt spectra
        SetStyle(hJetPt_R005,1); SetStyle(hJetPt_R01,2); SetStyle(hJetPt_R015,3); SetStyle(hJetPt_R02,4);
        SetStyle(hJetPt_R025,6); SetStyle(hJetPt_R03,7); SetStyle(hJetPt_R035,8); SetStyle(hJetPt_R04,9);
        hJetPt_R005->SetName("hJetPt_R005");hJetPt_R005->SetTitle("Jet Pt Spectrum (R=0.05)- Detector level");
        hJetPt_R01->SetName("hJetPt_R01");hJetPt_R01->SetTitle("Jet Pt Spectrum (R=0.1)- Detector level");
        hJetPt_R015->SetName("hJetPt_R015");hJetPt_R015->SetTitle("Jet Pt Spectrum (R=0.15)- Detector level");
        hJetPt_R02->SetName("hJetPt_R02");hJetPt_R02->SetTitle("Jet Pt Spectrum (R=0.2)- Detector level");
        hJetPt_R025->SetName("hJetPt_R025");hJetPt_R025->SetTitle("Jet Pt Spectrum (R=0.25)- Detector level");
        hJetPt_R03->SetName("hJetPt_R03");hJetPt_R03->SetTitle("Jet Pt Spectrum (R=0.3)- Detector level");
        hJetPt_R035->SetName("hJetPt_R035");hJetPt_R035->SetTitle("Jet Pt Spectrum (R=0.35)- Detector level");
        hJetPt_R04->SetName("hJetPt_R04");hJetPt_R04->SetTitle("Jet Pt Spectrum (R=0.4)- Detector level");

        //Jet eta distributions
        SetStyle(hJetEta_R005,1); SetStyle(hJetEta_R01,2); SetStyle(hJetEta_R015,3); SetStyle(hJetEta_R02,4); 
        SetStyle(hJetEta_R025,6); SetStyle(hJetEta_R03,7); SetStyle(hJetEta_R035,8); SetStyle(hJetEta_R04,9);
        hJetEta_R005->SetName("hJetEta_R005");hJetEta_R005->SetTitle("Jet #eta distribution (R=0.05)- Detector level");
        hJetEta_R01->SetName("hJetEta_R01");hJetEta_R01->SetTitle("Jet #eta distribution (R=0.1)- Detector level");
        hJetEta_R015->SetName("hJetEta_R015");hJetEta_R015->SetTitle("Jet #eta distribution (R=0.15)- Detector level");
        hJetEta_R02->SetName("hJetEta_R02");hJetEta_R02->SetTitle("Jet #eta distribution (R=0.2)- Detector level");
        hJetEta_R025->SetName("hJetEta_R025");hJetEta_R025->SetTitle("Jet #eta distribution (R=0.25)- Detector level");
        hJetEta_R03->SetName("hJetEta_R03");hJetEta_R03->SetTitle("Jet #eta distribution (R=0.3)- Detector level");
        hJetEta_R035->SetName("hJetEta_R035");hJetEta_R035->SetTitle("Jet #eta distribution (R=0.35)- Detector level");
        hJetEta_R04->SetName("hJetEta_R04");hJetEta_R04->SetTitle("Jet #eta distribution (R=0.4)- Detector level");
        //Matched jet spectra
                //pt spectra
        SetStyle(hJetPtMatched_R005,1); SetStyle(hJetPtMatched_R010,2);
        SetStyle(hJetPtMatched_R015,3); SetStyle(hJetPtMatched_R020,4);
        SetStyle(hJetPtMatched_R025,6); SetStyle(hJetPtMatched_R030,7);
        SetStyle(hJetPtMatched_R035,8); SetStyle(hJetPtMatched_R040,9);
                     //eta distributions
        SetStyle(hJetEtaMatched_R005,1); SetStyle(hJetEtaMatched_R010,2); SetStyle(hJetEtaMatched_R015,3); SetStyle(hJetEtaMatched_R020,4);
        SetStyle(hJetEtaMatched_R025,6); SetStyle(hJetEtaMatched_R030,7); SetStyle(hJetEtaMatched_R035,8); SetStyle(hJetEtaMatched_R040,9);
//Projections calculation
        //Dpt projections
        TH1D*pro_R005 = hDptR005->ProjectionY("pro_R005",Ptlow_bin,Pthigh_bin); TH1D*pro_R01 = hDptR010->ProjectionY("pro_R01",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R015 = hDptR015->ProjectionY("pro_R015",Ptlow_bin,Pthigh_bin); TH1D*pro_R02 = hDptR020->ProjectionY("pro_R02",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R025 = hDptR025->ProjectionY("pro_R025",Ptlow_bin,Pthigh_bin); TH1D*pro_R03 = hDptR030->ProjectionY("pro_R03",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R035 = hDptR035->ProjectionY("pro_R035",Ptlow_bin,Pthigh_bin);
        //DR projections
        TH1D*pro_DR005 = hDR005->ProjectionY("pro_DR005",Ptlow_bin,Pthigh_bin); TH1D*pro_DR01 = hDR010->ProjectionY("pro_DR01",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR015 = hDR015->ProjectionY("pro_DR015",Ptlow_bin,Pthigh_bin); TH1D*pro_DR02 = hDR020->ProjectionY("pro_DR02",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR025 = hDR025->ProjectionY("pro_DR025",Ptlow_bin,Pthigh_bin); TH1D*pro_DR03 = hDR030->ProjectionY("pro_DR03",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR035 = hDR035->ProjectionY("pro_DR035",Ptlow_bin,Pthigh_bin);

    pro_R005->SetTitle(TString::Format("#DeltaP_{t} between R=0.05 and R=0.1 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R01->SetTitle(TString::Format("#DeltaP_{t} between R=0.1 and R=0.15 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R015->SetTitle(TString::Format("#DeltaP_{t} between R=0.15 and R=0.2 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R02->SetTitle(TString::Format("#DeltaP_{t} between R=0.2 and R=0.25 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R025->SetTitle(TString::Format("#DeltaP_{t} between R=0.25 and R=0.3 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R03->SetTitle(TString::Format("#DeltaP_{t} between R=0.3 and R=0.35 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R035->SetTitle(TString::Format("#DeltaP_{t} between R=0.35 and R=0.4 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));

    pro_DR005->SetTitle(TString::Format("#DeltaR between R=0.05 and R=0.1 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR01->SetTitle(TString::Format("#DeltaR between R=0.1 and R=0.15 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR015->SetTitle(TString::Format("#DeltaR between R=0.15 and R=0.2 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR02->SetTitle(TString::Format("#DeltaR between R=0.2 and R=0.25 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR025->SetTitle(TString::Format("#DeltaR between R=0.25 and R=0.3 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR03->SetTitle(TString::Format("#DeltaR between R=0.3 and R=0.35 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR035->SetTitle(TString::Format("#DeltaR between R=0.35 and R=0.4 for jet P_{t}[%d,%d] (GeV/c)- Detector level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));

        SetStyle(pro_R005,1);SetStyle(pro_R01,2);SetStyle(pro_R015,3);SetStyle(pro_R02,4);SetStyle(pro_R025,6);SetStyle(pro_R03,7);SetStyle(pro_R035,8);
        pro_R005->Scale(1/pro_R005->Integral()); pro_R01->Scale(1/pro_R01->Integral()); pro_R015->Scale(1/pro_R015->Integral()); pro_R02->Scale(1/pro_R02->Integral());
        pro_R025->Scale(1/pro_R025->Integral()); pro_R03->Scale(1/pro_R03->Integral()); pro_R035->Scale(1/pro_R035->Integral());

        SetStyle(pro_DR005,1);SetStyle(pro_DR01,2);SetStyle(pro_DR015,3);SetStyle(pro_DR02,4);SetStyle(pro_DR025,6);SetStyle(pro_DR03,7);SetStyle(pro_DR035,8);
        pro_DR005->Scale(1/pro_DR005->Integral()); pro_DR01->Scale(1/pro_DR01->Integral()); pro_DR015->Scale(1/pro_DR015->Integral()); pro_DR02->Scale(1/pro_DR02->Integral());
        pro_DR025->Scale(1/pro_DR025->Integral()); pro_DR03->Scale(1/pro_DR03->Integral()); pro_DR035->Scale(1/pro_DR035->Integral());
//Mean & RMS graph calculation
         Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
         Double_t mean[7]={pro_R005->GetMean(),pro_R01->GetMean(),pro_R015->GetMean(),pro_R02->GetMean(),pro_R025->GetMean(),pro_R03->GetMean(),pro_R035->GetMean()};
         Double_t rms[7]={pro_R005->GetRMS(),pro_R01->GetRMS(),pro_R015->GetRMS(),pro_R02->GetRMS(),pro_R025->GetRMS(),pro_R03->GetRMS(),pro_R035->GetRMS()};
         Double_t mean_err[7]={pro_R005->GetMeanError(),pro_R01->GetMeanError(),pro_R015->GetMeanError(),pro_R02->GetMeanError(),pro_R025->GetMeanError(),pro_R03->GetMeanError(),pro_R035->GetMeanError()};
         Double_t rms_err[7]={pro_R005->GetRMSError(),pro_R01->GetRMSError(),pro_R015->GetRMSError(),pro_R02->GetRMSError(),pro_R025->GetRMSError(),pro_R03->GetRMSError(),pro_R035->GetRMSError()};
         Double_t R_err[7] = {0,0,0,0,0,0,0};

         auto Mean_gr = new TGraphErrors(7,R,mean,R_err,mean_err);
         Mean_gr->SetMarkerSize(3);
         Mean_gr->SetMarkerStyle(33);
         Mean_gr->SetTitle(TString::Format("Mean of the #DeltaP_{t} distributions for jet p_{t}[%d,%d] - Detector level;R_{low,jet}; #<#DeltaP_{t}#> (GeV/c)",Ptlow,Pthigh));
   
          auto RMS_gr = new TGraphErrors(7,R,rms,R_err,rms_err);
          RMS_gr->SetMarkerSize(3);
          RMS_gr->SetMarkerStyle(33);
          RMS_gr->SetTitle(TString::Format("Width of the #DeltaP_{t} projection distributions [%d,%d] - Detector level;R_{low,jet}; #sigma_{#DeltaP_{t}} (GeV/c)",Ptlow,Pthigh));

                //Truth level
       //Jet pt spectra
        SetStyle(hJetPt_R005_gen,1); SetStyle(hJetPt_R01_gen,2); SetStyle(hJetPt_R015_gen,3); SetStyle(hJetPt_R02_gen,4);
        SetStyle(hJetPt_R025_gen,6); SetStyle(hJetPt_R03_gen,7); SetStyle(hJetPt_R035_gen,8); SetStyle(hJetPt_R04_gen,9);
        hJetPt_R005_gen->SetName("hJetPt_R005_gen");hJetPt_R005_gen->SetTitle("Jet Pt Spectrum (R=0.05)- Truth level");
        hJetPt_R01_gen->SetName("hJetPt_R01_gen");hJetPt_R01_gen->SetTitle("Jet Pt Spectrum (R=0.1)- Truth level");
        hJetPt_R015_gen->SetName("hJetPt_R015_gen");hJetPt_R015_gen->SetTitle("Jet Pt Spectrum (R=0.15)- Truth level");
        hJetPt_R02_gen->SetName("hJetPt_R02_gen");hJetPt_R02_gen->SetTitle("Jet Pt Spectrum (R=0.2)- Truth level");
        hJetPt_R025_gen->SetName("hJetPt_R025_gen");hJetPt_R025_gen->SetTitle("Jet Pt Spectrum (R=0.25)- Truth level");
        hJetPt_R03_gen->SetName("hJetPt_R03_gen");hJetPt_R03_gen->SetTitle("Jet Pt Spectrum (R=0.3)- Truth level");
        hJetPt_R035_gen->SetName("hJetPt_R035_gen");hJetPt_R035_gen->SetTitle("Jet Pt Spectrum (R=0.35)- Truth level");
        hJetPt_R04_gen->SetName("hJetPt_R04_gen");hJetPt_R04_gen->SetTitle("Jet Pt Spectrum (R=0.4)- Truth level");

        //Jet eta distributions
        SetStyle(hJetEta_R005_gen,1); SetStyle(hJetEta_R01_gen,2); SetStyle(hJetEta_R015_gen,3); SetStyle(hJetEta_R02_gen,4);
        SetStyle(hJetEta_R025_gen,6); SetStyle(hJetEta_R03_gen,7); SetStyle(hJetEta_R035_gen,8); SetStyle(hJetEta_R04_gen,9);
        hJetEta_R005_gen->SetName("hJetEta_R005_gen");hJetEta_R005_gen->SetTitle("Jet #eta distribution (R=0.05)- Truth level");
        hJetEta_R01_gen->SetName("hJetEta_R01_gen");hJetEta_R01_gen->SetTitle("Jet #eta distribution (R=0.1)- Truth level");
        hJetEta_R015_gen->SetName("hJetEta_R015_gen");hJetEta_R015_gen->SetTitle("Jet #eta distribution (R=0.15)- Truth level");
        hJetEta_R02_gen->SetName("hJetEta_R02_gen");hJetEta_R02_gen->SetTitle("Jet #eta distribution (R=0.2)- Truth level");
        hJetEta_R025_gen->SetName("hJetEta_R025_gen");hJetEta_R025_gen->SetTitle("Jet #eta distribution (R=0.25)- Truth level");
        hJetEta_R03_gen->SetName("hJetEta_R03_gen");hJetEta_R03_gen->SetTitle("Jet #eta distribution (R=0.3)- Truth level");
        hJetEta_R035_gen->SetName("hJetEta_R035_gen");hJetEta_R035_gen->SetTitle("Jet #eta distribution (R=0.35)- Truth level");
        hJetEta_R04_gen->SetName("hJetEta_R04_gen");hJetEta_R04_gen->SetTitle("Jet #eta distribution (R=0.4)- Truth level");
        //Matched jet spectra
                //pt spectra
        SetStyle(hJetPtMatched_R005_gen,1); SetStyle(hJetPtMatched_R010_gen,2);
        SetStyle(hJetPtMatched_R015_gen,3); SetStyle(hJetPtMatched_R020_gen,4);
        SetStyle(hJetPtMatched_R025_gen,6); SetStyle(hJetPtMatched_R030_gen,7);
        SetStyle(hJetPtMatched_R035_gen,8); SetStyle(hJetPtMatched_R040_gen,9);
                     //eta distributions
        SetStyle(hJetEtaMatched_R005_gen,1); SetStyle(hJetEtaMatched_R010_gen,2); SetStyle(hJetEtaMatched_R015_gen,3); SetStyle(hJetEtaMatched_R020_gen,4);
        SetStyle(hJetEtaMatched_R025_gen,6); SetStyle(hJetEtaMatched_R030_gen,7); SetStyle(hJetEtaMatched_R035_gen,8); SetStyle(hJetEtaMatched_R040_gen,9);

//Projections calculation
        //Dpt projections
        TH1D*pro_R005_gen = hDptR005_gen->ProjectionY("pro_R005_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_R01_gen = hDptR010_gen->ProjectionY("pro_R01_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R015_gen = hDptR015_gen->ProjectionY("pro_R015_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_R02_gen = hDptR020_gen->ProjectionY("pro_R02_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R025_gen = hDptR025_gen->ProjectionY("pro_R025_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_R03_gen = hDptR030_gen->ProjectionY("pro_R03_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_R035_gen = hDptR035_gen->ProjectionY("pro_R035_gen",Ptlow_bin,Pthigh_bin);
        //DR projections
        TH1D*pro_DR005_gen = hDR005_gen->ProjectionY("pro_DR005_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_DR01_gen = hDR010_gen->ProjectionY("pro_DR01_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR015_gen = hDR015_gen->ProjectionY("pro_DR015_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_DR02_gen = hDR020_gen->ProjectionY("pro_DR02_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR025_gen = hDR025_gen->ProjectionY("pro_DR025_gen",Ptlow_bin,Pthigh_bin); TH1D*pro_DR03_gen = hDR030_gen->ProjectionY("pro_DR03_gen",Ptlow_bin,Pthigh_bin);
        TH1D*pro_DR035_gen = hDR035_gen->ProjectionY("pro_DR035_gen",Ptlow_bin,Pthigh_bin);

    pro_R005_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.05 and R=0.1 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R01_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.1 and R=0.15 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R015_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.15 and R=0.2 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R02_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.2 and R=0.25 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R025_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.25 and R=0.3 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R03_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.3 and R=0.35 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));
    pro_R035_gen->SetTitle(TString::Format("#DeltaP_{t} between R=0.35 and R=0.4 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaP_{t} (GeV/c); #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaP_{t}}",Ptlow,Pthigh));

    pro_DR005->SetTitle(TString::Format("#DeltaR between R=0.05 and R=0.1 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR01->SetTitle(TString::Format("#DeltaR between R=0.1 and R=0.15 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR015->SetTitle(TString::Format("#DeltaR between R=0.15 and R=0.2 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR02->SetTitle(TString::Format("#DeltaR between R=0.2 and R=0.25 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR025->SetTitle(TString::Format("#DeltaR between R=0.25 and R=0.3 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR03->SetTitle(TString::Format("#DeltaR between R=0.3 and R=0.35 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
    pro_DR035->SetTitle(TString::Format("#DeltaR between R=0.35 and R=0.4 for jet P_{t}[%d,%d] (GeV/c)- Truth level;#DeltaR; #frac{1}{#sigma_{jets}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));

        SetStyle(pro_R005_gen,1);SetStyle(pro_R01_gen,2);SetStyle(pro_R015_gen,3);SetStyle(pro_R02_gen,4);SetStyle(pro_R025_gen,6);SetStyle(pro_R03_gen,7);SetStyle(pro_R035_gen,8);
        pro_R005_gen->Scale(1/pro_R005_gen->Integral()); pro_R01_gen->Scale(1/pro_R01_gen->Integral()); pro_R015_gen->Scale(1/pro_R015_gen->Integral()); pro_R02_gen->Scale(1/pro_R02_gen->Integral());
        pro_R025_gen->Scale(1/pro_R025_gen->Integral()); pro_R03_gen->Scale(1/pro_R03_gen->Integral()); pro_R035_gen->Scale(1/pro_R035_gen->Integral());

        SetStyle(pro_DR005_gen,1);SetStyle(pro_DR01_gen,2);SetStyle(pro_DR015_gen,3);SetStyle(pro_DR02_gen,4);SetStyle(pro_DR025_gen,6);SetStyle(pro_DR03_gen,7);SetStyle(pro_DR035_gen,8);
        pro_DR005_gen->Scale(1/pro_DR005_gen->Integral()); pro_DR01_gen->Scale(1/pro_DR01_gen->Integral()); pro_DR015_gen->Scale(1/pro_DR015_gen->Integral()); 
        pro_DR02_gen->Scale(1/pro_DR02_gen->Integral());pro_DR025_gen->Scale(1/pro_DR025_gen->Integral()); pro_DR03_gen->Scale(1/pro_DR03_gen->Integral());
        pro_DR035_gen->Scale(1/pro_DR035_gen->Integral());

        //Mean & RMS graph calculation
       //  Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
         Double_t mean_gen[7]={pro_R005_gen->GetMean(),pro_R01_gen->GetMean(),pro_R015_gen->GetMean(),pro_R02_gen->GetMean(),pro_R025_gen->GetMean(),pro_R03_gen->GetMean(),pro_R035_gen->GetMean()};
         Double_t rms_gen[7]={pro_R005_gen->GetRMS(),pro_R01_gen->GetRMS(),pro_R015_gen->GetRMS(),pro_R02_gen->GetRMS(),pro_R025_gen->GetRMS(),pro_R03_gen->GetRMS(),pro_R035_gen->GetRMS()};
         Double_t mean_err_gen[7]={pro_R005_gen->GetMeanError(),pro_R01_gen->GetMeanError(),pro_R015_gen->GetMeanError(),pro_R02_gen->GetMeanError(),pro_R025_gen->GetMeanError(),pro_R03_gen->GetMeanError(),pro_R035_gen->GetMeanError()};
         Double_t rms_err_gen[7]={pro_R005_gen->GetRMSError(),pro_R01_gen->GetRMSError(),pro_R015_gen->GetRMSError(),pro_R02_gen->GetRMSError(),pro_R025_gen->GetRMSError(),pro_R03_gen->GetRMSError(),pro_R035_gen->GetRMSError()};
  //       Double_t R_err[7] = {0,0,0,0,0,0,0};

         auto Mean_gen_gr = new TGraphErrors(7,R,mean_gen,R_err,mean_err_gen);
         Mean_gen_gr->SetMarkerSize(3);
         Mean_gen_gr->SetMarkerStyle(33);
         Mean_gen_gr->SetTitle(TString::Format("Mean of the #DeltaP_{t} distributions for jet p_{t}[%d,%d] - Truth level;R_{low,jet}; #<#DeltaP_{t}#> (GeV/c)",Ptlow,Pthigh));

          auto RMS_gen_gr = new TGraphErrors(7,R,rms_gen,R_err,rms_err_gen);
          RMS_gen_gr->SetMarkerSize(3);
          RMS_gen_gr->SetMarkerStyle(33);
          RMS_gen_gr->SetTitle(TString::Format("Width of the #DeltaP_{t} projection distributions [%d,%d] - Truth level;R_{low,jet}; #sigma_{#DeltaP_{t}} (GeV/c)",Ptlow,Pthigh));


//--------------------------------------Plotting section-------------------------------

                //Detector level
        //Jet pt spectra
        TCanvas *c1 = new TCanvas("c1","Jet Pt spectra-Detector level",1400,1000);
       c1->SetLogy(1);
        c1->SetGridy(1);
//      hJetPt_R01->SetMaximum(10);
    //   c1->DrawFrame(0,1,200,1e7,"Overview of jet P_{t} spectra- ALICE pp data;p_{t} (GeV/c);N");
        c1->DrawFrame(0,1e-10,200,10*hJetPt_R005->GetMaximum(),"Overview of jet P_{t} spectra- Detector level;p_{t} (GeV/c);#sigma_{jets}");
        hJetPt_R005->Draw("same");hJetPt_R01->Draw("same"); hJetPt_R015->Draw("same"); hJetPt_R02->Draw("same"); hJetPt_R025->Draw("same"); hJetPt_R03->Draw("same"); hJetPt_R035->Draw("same");
        hJetPt_R04->Draw("same");

        auto legend = new TLegend(.3,.4,.6,.6);
        legend->SetNColumns(2);
        legend->AddEntry(hJetPt_R005,"R = 0.05","p"); legend->AddEntry(hJetPt_R01,"R = 0.1","p"); legend->AddEntry(hJetPt_R015,"R = 0.15","p"); legend->AddEntry(hJetPt_R02,"R = 0.2","p");
        legend->AddEntry(hJetPt_R025,"R = 0.25","p"); legend->AddEntry(hJetPt_R03,"R = 0.3","p"); legend->AddEntry(hJetPt_R035,"R = 0.35","p"); legend->AddEntry(hJetPt_R04,"R = 0.4","p");
        legend->Draw();

        //Jet eta distributions
        TCanvas *c1a = new TCanvas("c1a","Jet Eta distribution-Detector level",1200,1200);
        c1a->DrawFrame(-.6,0.9*hJetEta_R04->GetMinimum(),.6,1.1*hJetEta_R04->GetMaximum(),"Overview of jet #eta spectra- Detector level;#eta;#sigma_{jets}");
        hJetEta_R005->Draw("same");hJetEta_R01->Draw("same"); hJetEta_R015->Draw("same"); hJetEta_R02->Draw("same"); hJetEta_R025->Draw("same"); hJetEta_R03->Draw("same");
        hJetEta_R035->Draw("same"); hJetEta_R04->Draw("same");
        legend->Draw();

        //Matched jet pt spectra
        TCanvas *c1b = new TCanvas("c1b","Matched jet Pt spectra-Detector level",1400,1000);
        c1b->SetLogy(1);
        c1b->SetGridy(1);
        //c1b->DrawFrame(0,1,200,1e7,"Overview of matched jet P_{t} spectra- ALICE pp data;p_{t} (GeV/c);N");
        c1b->DrawFrame(0,1e-10,200,10*hJetPtMatched_R005->GetMaximum(),"Overview of matched jet P_{t} spectra- Detector level;p_{t} (GeV/c);#sigma_{jets}");
        hJetPtMatched_R005->Draw("same");hJetPtMatched_R010->Draw("same"); hJetPtMatched_R015->Draw("same"); hJetPtMatched_R020->Draw("same"); hJetPtMatched_R025->Draw("same");
        hJetPtMatched_R030->Draw("same"); hJetPtMatched_R035->Draw("same"); hJetPtMatched_R040->Draw("same");
        legend->Draw();

        //Matched jet eta distributions
        TCanvas *c1c = new TCanvas("c1c","Matched jet Eta distribution-Detector level",1000,1000);
        c1c->DrawFrame(-.6,0.9*hJetEtaMatched_R040->GetMinimum(),.6,1.1*hJetEtaMatched_R040->GetMaximum(),"Overview of matched jet #eta spectra- Detector level;#eta;#sigma_{jets}");
        hJetEtaMatched_R005->Draw("same"); hJetEtaMatched_R010->Draw("same"); hJetEtaMatched_R015->Draw("same"); hJetEtaMatched_R020->Draw("same"); hJetEtaMatched_R025->Draw("same");
        hJetEtaMatched_R030->Draw("same"); hJetEtaMatched_R035->Draw("same"); hJetEtaMatched_R040->Draw("same");
        legend->Draw();

        //Delta pt projections
        TCanvas*c2 = new TCanvas("c2","DeltaPt projections overview- Detector level",1400,1400);
        c2->DrawFrame(-20,1e-8,80,10,Form("#Deltap_{t} distributions overview for jet p_{t} [%d,%d]- Detector level;#DeltaP_{t} (GeV/c);#frac{1}{#sigma_{jets}} #frac{d#sigma}{d#Deltap_{t}}",Ptlow,Pthigh));
        c2->SetLogy(1);
        c2->SetGridy(1);
        pro_R005->Draw("same");pro_R01->Draw("same");pro_R015->Draw("same");pro_R02->Draw("same");pro_R025->Draw("same");pro_R03->Draw("same");pro_R035->Draw("same");

        auto legend1 = new TLegend(.16,.17,.56,.47);
        legend1->SetNColumns(2);
        legend1->AddEntry(pro_R005,"R = 0.05 to R = 0.1","p"); legend1->AddEntry(pro_R01,"R = 0.1 to R = 0.15","p"); legend1->AddEntry(pro_R015,"R = 0.15 to R = 0.2","p");
        legend1->AddEntry(pro_R02,"R = 0.2 to R = 0.25","p"); legend1->AddEntry(pro_R025,"R = 0.25 to R = 0.3","p"); legend1->AddEntry(pro_R03,"R = 0.3 to R = 0.35","p");
        legend1->AddEntry(pro_R035,"R = 0.35 to R = 0.4","p");
        legend1->Draw();
        
        //Delta R projections
        TCanvas*c3 = new TCanvas("c3","DeltaR projections overview-Detector level",1400,1400);
        c3->DrawFrame(0,1e-5,.3,10,Form("#DeltaR distributions overview for jet p_{t} [%d,%d]- Detector level;#DeltaR (GeV/c);#frac{1}{#sigma_{jets}} #frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
        c3->SetLogy(1);
        c3->SetGridy(1);
        pro_DR005->Draw("same");pro_DR01->Draw("same");pro_DR015->Draw("same");pro_DR02->Draw("same");pro_DR025->Draw("same");pro_DR03->Draw("same");pro_DR035->Draw("same");
        legend1->Draw();
        //Mean & RMS plots

                TCanvas*c4 = new TCanvas("c4","Dpt projection Mean-Detector level",1200,1200);
                c4->DrawFrame(0,0,.4,15,TString::Format("Mean of the #DeltaP_{t} projection distributions [%d,%d] Detector level;R_{low}; <#DeltaP_{t}> (GeV/c)",Ptlow,Pthigh));
                c4->SetGridy(1);
                Mean_gr->Draw("LP");
                c4->SaveAs(Form("./Plots/Mean_%d_%d_det.png",Ptlow,Pthigh));

                TCanvas*c4a = new TCanvas("c4a","Dpt projection RMS-Detector level",1200,1200);
                c4a->DrawFrame(0,0,.4,15,TString::Format("RMS of the #DeltaP_{t} projection distributions [%d,%d] Detector level;R_{low}; #sigma_{#DeltaP_{t}} (GeV/c)",Ptlow,Pthigh));
                c4a->SetGridy(1);
                RMS_gr->Draw("LP");
                c4a->SaveAs(Form("./Plots/RMS_%d_%d_det.png",Ptlow,Pthigh));

                //Truth level

        //Jet pt spectra
        TCanvas *c1_gen = new TCanvas("c1_gen","Jet Pt spectra-Truth level",1400,1000);
       c1_gen->SetLogy(1);
        c1_gen->SetGridy(1);
    //   c1->DrawFrame(0,1,200,1e7,"Overview of jet P_{t} spectra- ALICE pp data;p_{t} (GeV/c);N");
        c1_gen->DrawFrame(0,1e-10,200,10*hJetPt_R005_gen->GetMaximum(),"Overview of jet P_{t} spectra- Truth level;p_{t} (GeV/c);#sigma_{jets}");
        hJetPt_R005_gen->Draw("same");hJetPt_R01_gen->Draw("same"); hJetPt_R015_gen->Draw("same"); hJetPt_R02_gen->Draw("same"); hJetPt_R025_gen->Draw("same"); hJetPt_R03_gen->Draw("same");
        hJetPt_R035_gen->Draw("same");hJetPt_R04_gen->Draw("same");

 //       auto legend = new TLegend(.3,.4,.6,.6);
 //       legend->SetNColumns(2);
//        legend->AddEntry(hJetPt_R005,"R = 0.05","p"); legend->AddEntry(hJetPt_R01,"R = 0.1","p"); legend->AddEntry(hJetPt_R015,"R = 0.15","p"); legend->AddEntry(hJetPt_R02,"R = 0.2","p");
//        legend->AddEntry(hJetPt_R025,"R = 0.25","p"); legend->AddEntry(hJetPt_R03,"R = 0.3","p"); legend->AddEntry(hJetPt_R035,"R = 0.35","p"); legend->AddEntry(hJetPt_R04,"R = 0.4","p");
        legend->Draw();

        //Jet eta distributions
        TCanvas *c1a_gen = new TCanvas("c1a_gen","Jet Eta distribution-Truth level",1200,1200);
        c1a_gen->DrawFrame(-.6,0.9*hJetEta_R04_gen->GetMinimum(),.6,1.1*hJetEta_R04_gen->GetMaximum(),"Overview of jet #eta spectra- Truth level;#eta;#sigma_{jets}");
        hJetEta_R005_gen->Draw("same");hJetEta_R01_gen->Draw("same"); hJetEta_R015_gen->Draw("same"); hJetEta_R02_gen->Draw("same"); hJetEta_R025_gen->Draw("same"); hJetEta_R03_gen->Draw("same");
        hJetEta_R035_gen->Draw("same"); hJetEta_R04_gen->Draw("same");
        legend->Draw();

        //Matched jet pt spectra
        TCanvas *c1b_gen = new TCanvas("c1b_gen","Matched jet Pt spectra- Truth level",1400,1000);
        c1b_gen->SetLogy(1);
        c1b_gen->SetGridy(1);
        //c1b->DrawFrame(0,1,200,1e7,"Overview of matched jet P_{t} spectra- ALICE pp data;p_{t} (GeV/c);N");
        c1b_gen->DrawFrame(0,1e-10,200,10*hJetPtMatched_R005_gen->GetMaximum(),"Overview of matched jet P_{t} spectra- Truth level;p_{t} (GeV/c);#sigma_{jets}");
        hJetPtMatched_R005_gen->Draw("same");hJetPtMatched_R010_gen->Draw("same"); hJetPtMatched_R015_gen->Draw("same"); hJetPtMatched_R020_gen->Draw("same"); hJetPtMatched_R025_gen->Draw("same");
        hJetPtMatched_R030_gen->Draw("same"); hJetPtMatched_R035_gen->Draw("same"); hJetPtMatched_R040_gen->Draw("same");
        legend->Draw();

        //Matched jet eta distributions
        TCanvas *c1c_gen = new TCanvas("c1c_gen","Matched jet Eta distribution- Truth level",1000,1000);
        c1c_gen->DrawFrame(-.6,0.9*hJetEtaMatched_R040_gen->GetMinimum(),.6,1.1*hJetEtaMatched_R040_gen->GetMaximum(),"Overview of matched jet #eta spectra- Truth level;#eta;#sigma_{jets}");
        hJetEtaMatched_R005_gen->Draw("same"); hJetEtaMatched_R010_gen->Draw("same"); hJetEtaMatched_R015_gen->Draw("same"); hJetEtaMatched_R020_gen->Draw("same"); hJetEtaMatched_R025_gen->Draw("same");
        hJetEtaMatched_R030_gen->Draw("same"); hJetEtaMatched_R035_gen->Draw("same"); hJetEtaMatched_R040_gen->Draw("same");
        legend->Draw();

        //Delta pt projections
        TCanvas*c2_gen = new TCanvas("c2_gen","DeltaPt projections overview- Truth level",1400,1400);
        c2_gen->DrawFrame(-20,1e-8,80,10,Form("#Deltap_{t} distributions overview for jet p_{t} [%d,%d]- Truth level;#DeltaP_{t} (GeV/c);#frac{1}{#sigma_{jets}} #frac{d#sigma}{d#Deltap_{t}}",Ptlow,Pthigh));
        c2_gen->SetLogy(1);
        c2_gen->SetGridy(1);
        pro_R005_gen->Draw("same");pro_R01_gen->Draw("same");pro_R015_gen->Draw("same");pro_R02_gen->Draw("same");pro_R025_gen->Draw("same");pro_R03_gen->Draw("same");pro_R035_gen->Draw("same");

//        auto legend1 = new TLegend(.16,.17,.56,.47);
//        legend1->SetNColumns(2);
//        legend1->AddEntry(pro_R005,"R = 0.05 to R = 0.1","p"); legend1->AddEntry(pro_R01,"R = 0.1 to R = 0.15","p"); legend1->AddEntry(pro_R015,"R = 0.15 to R = 0.2","p");
//        legend1->AddEntry(pro_R02,"R = 0.2 to R = 0.25","p"); legend1->AddEntry(pro_R025,"R = 0.25 to R = 0.3","p"); legend1->AddEntry(pro_R03,"R = 0.3 to R = 0.35","p");
//        legend1->AddEntry(pro_R035,"R = 0.35 to R = 0.4","p");
        legend1->Draw();

        //Delta R projections
        TCanvas*c3_gen = new TCanvas("c3_gen","DeltaR projections overview- Truth level",1400,1400);
        c3_gen->DrawFrame(0,1e-5,.3,10,Form("#DeltaR distributions overview for jet p_{t} [%d,%d]- Truth level;#DeltaR (GeV/c);#frac{1}{#sigma_{jets}} #frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
        c3_gen->SetLogy(1);
        c3_gen->SetGridy(1);
        pro_DR005_gen->Draw("same");pro_DR01_gen->Draw("same");pro_DR015_gen->Draw("same");pro_DR02_gen->Draw("same");pro_DR025_gen->Draw("same");pro_DR03_gen->Draw("same");pro_DR035_gen->Draw("same");
        legend1->Draw();

       //Mean & RMS plots

                TCanvas*c4_gen = new TCanvas("c4_gen","Dpt projection Mean- Truth level",1200,1200);
                c4_gen->DrawFrame(0,0,.4,15,TString::Format("Mean of the #DeltaP_{t} projection distributions [%d,%d] Truth level;R_{low}; <#DeltaP_{t}> (GeV/c)",Ptlow,Pthigh));
                c4_gen->SetGridy(1);
                Mean_gen_gr->Draw("LP");
                c4->SaveAs(Form("./Plots/Mean_%d_%d_gen.png",Ptlow,Pthigh));

                TCanvas*c4a_gen = new TCanvas("c4a_gen","Dpt projection RMS- Truth level",1200,1200);
                c4a_gen->DrawFrame(0,0,.4,15,TString::Format("RMS of the #DeltaP_{t} projection distributions [%d,%d] Truth level;R_{low}; #sigma_{#DeltaP_{t}} (GeV/c)",Ptlow,Pthigh));
                c4a_gen->SetGridy(1);
                RMS_gen_gr->Draw("LP");
                c4a_gen->SaveAs(Form("./Plots/RMS_%d_%d_gen.png",Ptlow,Pthigh));


//-------------------------------------Writing the output to a file---------------------
TFile*sum = new TFile(TString::Format("EFData_summary_%d_%d_ppMC_smallR.root",Ptlow,Pthigh),"RECREATE",TString::Format("EFData_summary_%d_%d_ppMC_smallR.root",Ptlow,Pthigh));
sum->cd();
                //Detector level
        hJetPt_R005->Write();hJetPt_R01->Write();hJetPt_R015->Write();hJetPt_R02->Write();hJetPt_R025->Write();hJetPt_R03->Write();hJetPt_R035->Write();hJetPt_R04->Write();
        hJetEta_R005->Write();hJetEta_R01->Write();hJetEta_R015->Write();hJetEta_R02->Write();hJetEta_R025->Write();hJetEta_R03->Write();hJetEta_R035->Write();hJetEta_R04->Write();
        hJetPtMatched_R005->Write();hJetPtMatched_R010->Write();hJetPtMatched_R015->Write();hJetPtMatched_R020->Write();hJetPtMatched_R025->Write();hJetPtMatched_R030->Write();
        hJetPtMatched_R035->Write();hJetPtMatched_R040->Write();
        hJetEtaMatched_R005->Write();hJetEtaMatched_R010->Write();hJetEtaMatched_R015->Write();hJetEtaMatched_R020->Write();hJetEtaMatched_R025->Write();hJetEtaMatched_R030->Write();
        hJetEtaMatched_R035->Write();hJetEtaMatched_R040->Write();
        pro_DR005->Write();pro_DR01->Write();pro_DR015->Write();pro_DR02->Write();pro_DR025->Write();pro_DR03->Write();pro_DR035->Write();
        pro_R005->Write();pro_R01->Write();pro_R015->Write();pro_R02->Write();pro_R025->Write();pro_R03->Write();pro_R035->Write();
        RMS_gr->Write(TString::Format("RMS_graph_%d_%d",Ptlow,Pthigh));Mean_gr->Write(TString::Format("Mean_graph_%d_%d",Ptlow,Pthigh));

                //Truth level
        hJetPt_R005_gen->Write();hJetPt_R01_gen->Write();hJetPt_R015_gen->Write();hJetPt_R02_gen->Write();hJetPt_R025_gen->Write();hJetPt_R03_gen->Write();hJetPt_R035_gen->Write();hJetPt_R04_gen->Write();
        hJetEta_R005_gen->Write();hJetEta_R01_gen->Write();hJetEta_R015_gen->Write();hJetEta_R02_gen->Write();hJetEta_R025_gen->Write();hJetEta_R03_gen->Write();hJetEta_R035_gen->Write();hJetEta_R04_gen->Write();
        hJetPtMatched_R005_gen->Write();hJetPtMatched_R010_gen->Write();hJetPtMatched_R015_gen->Write();hJetPtMatched_R020_gen->Write();hJetPtMatched_R025_gen->Write();hJetPtMatched_R030_gen->Write();
        hJetPtMatched_R035_gen->Write();hJetPtMatched_R040_gen->Write();
        hJetEtaMatched_R005_gen->Write();hJetEtaMatched_R010_gen->Write();hJetEtaMatched_R015_gen->Write();hJetEtaMatched_R020_gen->Write();hJetEtaMatched_R025_gen->Write();hJetEtaMatched_R030_gen->Write();
        hJetEtaMatched_R035_gen->Write();hJetEtaMatched_R040_gen->Write();
        pro_DR005_gen->Write();pro_DR01_gen->Write();pro_DR015_gen->Write();pro_DR02_gen->Write();pro_DR025_gen->Write();pro_DR03_gen->Write();pro_DR035_gen->Write();
        pro_R005_gen->Write();pro_R01_gen->Write();pro_R015_gen->Write();pro_R02_gen->Write();pro_R025_gen->Write();pro_R03_gen->Write();pro_R035_gen->Write();
        RMS_gen_gr->Write(TString::Format("RMS_graph_gen_%d_%d",Ptlow,Pthigh));Mean_gen_gr->Write(TString::Format("Mean_graph_gen_%d_%d",Ptlow,Pthigh));


sum->Write();
}

  void SetStyle(TH1* h1, int kColor){
      
                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(2); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(23);
                  else h1->SetMarkerStyle(33);
                 }

