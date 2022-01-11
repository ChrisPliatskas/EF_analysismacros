void EnergyFlowCalculator_MCvariant(const char* fname, int Ptlow, int Pthigh){
	
	//Open the file and retrieve the general list of the histograms
	TFile*f1 = TFile::Open(fname);
	AliEmcalList* ali;
	f1->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_MCprod_GenDet_histos",ali);
   
	//Retrieving the  DeltaR histograms
       
         //Detector level
        TH2D* hDR01 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R10_0"));
	TH2D* hDR02 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R20_0"));
	TH2D* hDR03 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R30_0"));
     
        //Generator level
        TH2D* hDR01_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R10_gen_0"));
        TH2D* hDR02_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R20_gen_0"));
        TH2D* hDR03_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R30_gen_0"));

        int Ptwidth= int(hDR01->GetXaxis()->GetBinWidth(0));
        int Ptlow_bin =hDR01->GetXaxis()->FindBin(Ptlow);
        int Pthigh_bin = hDR01->GetXaxis()->FindBin(Pthigh);

	//Retrieving the DeltaPt histograms
        
        //Detector level
	TH2D* hDptR01 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R10_0"));
	TH2D* hDptR02 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R20_0"));
	TH2D* hDptR03 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R30_0"));

        //Generator level
        TH2D* hDptR01_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R10_gen_0"));
        TH2D* hDptR02_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R20_gen_0"));
        TH2D* hDptR03_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R30_gen_0"));

        //Response matrix for Dpt
/*        THnSparseD* ReponseR01 = static_cast<THnSparseD*>(ali->FindObject("ResponseMatrix_R10"));
        THnSparseD* ReponseR02 = static_cast<THnSparseD*>(ali->FindObject("ResponseMatrix_R20"));
        THnSparseD* ReponseR03 = static_cast<THnSparseD*>(ali->FindObject("ResponseMatrix_R30"));
        TH2D* ResponseR01 = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_R10"));
        TH2D* ResponseR02 = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_R20"));
        TH2D* ResponseR03 = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_R30"));
        
        //Response matrix for pt
        TH2D* ResponseR01pt = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_pt_R10"));
        TH2D* ResponseR02pt = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_pt_R20"));
        TH2D* ResponseR03pt = static_cast<TH2D*>(ali->FindObject("ResponseMatrix_pt_R30"));
*/
	//Retrieving the matched jet spectra 
        //Detector level
	TH1D* hJetPtMatched_R01 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R10_0"));
	TH1D* hJetPtMatched_R02 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R20_0"));
	TH1D* hJetPtMatched_R03 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R30_0"));
	TH1D* hJetPtMatched_R04 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R40_0"));

        TH1D* hJetEtaMatched_R01 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R10_0"));
        TH1D* hJetEtaMatched_R02 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R20_0"));
        TH1D* hJetEtaMatched_R03 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R30_0"));
        TH1D* hJetEtaMatched_R04 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R40_0"));

        // Generator level
        TH1D* hJetPtMatched_R01_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R10_gen_0"));
        TH1D* hJetPtMatched_R02_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R20_gen_0"));
        TH1D* hJetPtMatched_R03_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R30_gen_0"));
        TH1D* hJetPtMatched_R04_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R40_gen_0"));

        TH1D* hJetEtaMatched_R01_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R10_gen_0"));
        TH1D* hJetEtaMatched_R02_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R20_gen_0"));
        TH1D* hJetEtaMatched_R03_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R30_gen_0"));
        TH1D* hJetEtaMatched_R04_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R40_gen_0"));

/*
	//Pt vs DR vs Dpt
        //Detector level
	TH3D*hJetPtDeltaRDeltaPt_R10 = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R10"));
	TH3D*hJetPtDeltaRDeltaPt_R20 = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R20"));
	TH3D*hJetPtDeltaRDeltaPt_R30 = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R30"));
        
        //Generator level
        TH3D*hJetPtDeltaRDeltaPt_R10_gen = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R10_gen"));
        TH3D*hJetPtDeltaRDeltaPt_R20_gen = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R20_gen"));
        TH3D*hJetPtDeltaRDeltaPt_R30_gen = static_cast<TH3D*>(ali->FindObject("hJetPtDeltaRDeltaPt_R30_gen"));
*/
/*      //--------------- Commenting this section our until the Filling of Deta plots is fixed
	//Eta vs DR
//	TH2D*hEtaJetDeltaR_R10 = static_cast<TH2D*>(ali->FindObject("hEtaJetDeltaR_R10"));
//	TH2D*hEtaJetDeltaR_R20 = static_cast<TH2D*>(ali->FindObject("hEtaJetDeltaR_R20"));
//	TH2D*hEtaJetDeltaR_R30 = static_cast<TH2D*>(ali->FindObject("hEtaJetDeltaR_R30"));

	//Dpt vs Pt vs DEta
        //Detector level
	TH3D*hDeltaPtvPtvDeltaEta_R10 = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R10"));
	TH3D*hDeltaPtvPtvDeltaEta_R20 = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R20"));
	TH3D*hDeltaPtvPtvDeltaEta_R30 = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R30"));
        
        //Generator level
        TH3D*hDeltaPtvPtvDeltaEta_R10_gen = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R10_gen"));
        TH3D*hDeltaPtvPtvDeltaEta_R20_gen = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R20_gen"));
        TH3D*hDeltaPtvPtvDeltaEta_R30_gen = static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvDeltaEta_R30_gen"));

*/

	//Dpt vs Pt vs Multiplicity
        //Detector level
	TH3D*hDeltaPtvPtvMultiplicity_R10 =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R10_0"));
	TH3D*hDeltaPtvPtvMultiplicity_R20 =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R20_0"));
	TH3D*hDeltaPtvPtvMultiplicity_R30 =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R30_0"));

        //Generator level
        TH3D*hDeltaPtvPtvMultiplicity_R10_gen =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R10_gen_0"));
        TH3D*hDeltaPtvPtvMultiplicity_R20_gen =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R20_gen_0"));
        TH3D*hDeltaPtvPtvMultiplicity_R30_gen =static_cast<TH3D*>(ali->FindObject("hDeltaPtvPtvMultiplicity_R30_gen_0"));


	//Retrieving the lists/collections for each jet container

        //Generator level
	THashList*jetR01_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR010_mcparticles_pT0150_E_scheme"));
//        THashList*jetR01_gen = static_cast<THashList*>(ali->FindObject("GenJet_AKTChargedR010_mcparticles_pT0150_E_scheme"));
	THashList*jetR02_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR020_mcparticles_pT0150_E_scheme"));
//        THashList*jetR02_gen = static_cast<THashList*>(ali->FindObject("GenJet_AKTChargedR020_mcparticles_pT0150_E_scheme"));
	THashList*jetR03_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR030_mcparticles_pT0150_E_scheme"));
//        THashList*jetR03_gen = static_cast<THashList*>(ali->FindObject("GenJet_AKTChargedR030_mcparticles_pT0150_E_scheme"));
        THashList*jetR04_gen = static_cast<THashList*>(ali->FindObject("truthJet_AKTChargedR040_mcparticles_pT0150_E_scheme"));
 //       THashList*jetR04_gen = static_cast<THashList*>(ali->FindObject("GenJet_AKTChargedR040_mcparticles_pT0150_E_scheme"));	
        
        //Detector level
        THashList*jetR01 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR010_tracks_pT0150_E_scheme"));
 //       THashList*jetR01 = static_cast<THashList*>(ali->FindObject("DetJet_AKTChargedR010_tracks_pT0150_E_scheme"));
        THashList*jetR02 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR020_tracks_pT0150_E_scheme"));
   //     THashList*jetR02 = static_cast<THashList*>(ali->FindObject("DetJet_AKTChargedR020_tracks_pT0150_E_scheme"));
        THashList*jetR03 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR030_tracks_pT0150_E_scheme"));
   //     THashList*jetR03 = static_cast<THashList*>(ali->FindObject("DetJet_AKTChargedR030_tracks_pT0150_E_scheme"));  
        THashList*jetR04 = static_cast<THashList*>(ali->FindObject("Jet_AKTChargedR040_tracks_pT0150_E_scheme"));
    //    THashList*jetR04 = static_cast<THashList*>(ali->FindObject("DetJet_AKTChargedR040_tracks_pT0150_E_scheme"));


	//Retrieving some basic histograms (pt, phi, eta) for each jet container
        //Detector level
			//jet R=0.1
	TH1D*hJetPt_R01 = static_cast<TH1D*>(jetR01->FindObject("histJetPt_0"));
     //	 hJetPt_R01->Sumw2();
	TH1D*hJetPhi_R01 = static_cast<TH1D*>(jetR01->FindObject("histJetPhi_0"));
	TH1D*hJetEta_R01 = static_cast<TH1D*>(jetR01->FindObject("histJetEta_0"));

			//jet R=0.2
	TH1D*hJetPt_R02 = static_cast<TH1D*>(jetR02->FindObject("histJetPt_0"));
     //  hJetPt_R02->Sumw2();
	TH1D*hJetPhi_R02 = static_cast<TH1D*>(jetR02->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R02 = static_cast<TH1D*>(jetR02->FindObject("histJetEta_0"));
			
			//jet R=0.3
	TH1D*hJetPt_R03 = static_cast<TH1D*>(jetR03->FindObject("histJetPt_0"));
     //  hJetPt_R03->Sumw2();
	TH1D*hJetPhi_R03 = static_cast<TH1D*>(jetR03->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R03 = static_cast<TH1D*>(jetR03->FindObject("histJetEta_0"));

			//jet R=0.4
	TH1D*hJetPt_R04 = static_cast<TH1D*>(jetR04->FindObject("histJetPt_0"));
     //  hJetPt_R04->Sumw2();
	TH1D*hJetPhi_R04 = static_cast<TH1D*>(jetR04->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R04 = static_cast<TH1D*>(jetR04->FindObject("histJetEta_0"));
        
        //Generator level
                        //jet R=0.1
        TH1D*hJetPt_R01_gen = static_cast<TH1D*>(jetR01_gen->FindObject("histJetPt_0"));
      //  hJetPt_R01_gen->Sumw2();
        TH1D*hJetPhi_R01_gen = static_cast<TH1D*>(jetR01_gen->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R01_gen = static_cast<TH1D*>(jetR01_gen->FindObject("histJetEta_0"));

                        //jet R=0.2
        TH1D*hJetPt_R02_gen = static_cast<TH1D*>(jetR02_gen->FindObject("histJetPt_0"));
       // hJetPt_R02_gen->Sumw2();
        TH1D*hJetPhi_R02_gen = static_cast<TH1D*>(jetR02_gen->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R02_gen = static_cast<TH1D*>(jetR02_gen->FindObject("histJetEta_0"));

                        //jet R=0.3
        TH1D*hJetPt_R03_gen = static_cast<TH1D*>(jetR03_gen->FindObject("histJetPt_0"));
       // hJetPt_R03_gen->Sumw2();
        TH1D*hJetPhi_R03_gen = static_cast<TH1D*>(jetR03_gen->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R03_gen = static_cast<TH1D*>(jetR03_gen->FindObject("histJetEta_0"));

                        //jet R=0.4
        TH1D*hJetPt_R04_gen = static_cast<TH1D*>(jetR04_gen->FindObject("histJetPt_0"));
       // hJetPt_R04_gen->Sumw2();
        TH1D*hJetPhi_R04_gen = static_cast<TH1D*>(jetR04_gen->FindObject("histJetPhi_0"));
        TH1D*hJetEta_R04_gen = static_cast<TH1D*>(jetR04_gen->FindObject("histJetEta_0"));

//------------------------Histogram manipulation will happen here---------------------

        //Response matrix section
        //Dpt
   /*     ReponseR01->GetAxis(0)->SetRange(Ptlow_bin,Pthigh_bin); ReponseR01->GetAxis(1)->SetRange(Ptlow,Pthigh);
        ReponseR02->GetAxis(0)->SetRange(Ptlow_bin,Pthigh_bin); ReponseR02->GetAxis(1)->SetRange(Ptlow,Pthigh);
        ReponseR03->GetAxis(0)->SetRange(Ptlow_bin,Pthigh_bin); ReponseR03->GetAxis(1)->SetRange(Ptlow,Pthigh);
       
        TH2D*RM_pro_R01 = ReponseR01->Projection(3,2);
        TH2D*RM_pro_R02 = ReponseR02->Projection(3,2);
        TH2D*RM_pro_R03 = ReponseR03->Projection(3,2);
*/
        //Detector level
	hJetPt_R01->SetLineColor(kBlue+2); hJetPt_R01->SetLineWidth(2);hJetPt_R01->SetMarkerStyle(33); hJetPt_R01->SetMarkerColor(kBlue+2);hJetPt_R01->SetMarkerSize(2);
	hJetEta_R01->SetLineColor(kBlue+2); hJetEta_R01->SetLineWidth(2);hJetEta_R01->SetMarkerStyle(33); hJetEta_R01->SetMarkerColor(kBlue+2);hJetEta_R01->SetMarkerSize(2);
	hJetPhi_R01->SetLineColor(kBlue+2);

        hJetPt_R02->SetLineColor(2); hJetPt_R02->SetLineWidth(2);hJetPt_R02->SetMarkerStyle(33); hJetPt_R02->SetMarkerColor(2);hJetPt_R02->SetMarkerSize(2);
	hJetEta_R02->SetLineColor(2); hJetEta_R02->SetLineWidth(2);hJetEta_R02->SetMarkerStyle(33);hJetEta_R02->SetMarkerColor(2);hJetEta_R02->SetMarkerSize(2);
	hJetPhi_R02->SetLineColor(2);

	hJetPt_R03->SetLineColor(kGreen+2); hJetPt_R03->SetLineWidth(2);hJetPt_R03->SetMarkerStyle(33); hJetPt_R03->SetMarkerColor(kGreen+2); hJetPt_R03->SetMarkerSize(2);
	hJetEta_R03->SetLineColor(kGreen+2); hJetEta_R03->SetLineWidth(2);hJetEta_R03->SetMarkerStyle(33); hJetEta_R03->SetMarkerColor(kGreen+2); hJetEta_R03->SetMarkerSize(2); 
	hJetPhi_R03->SetLineColor(kGreen+2);
	
	hJetPt_R04->SetLineColor(kMagenta+2); hJetPt_R04->SetLineWidth(2);hJetPt_R04->SetMarkerStyle(33); hJetPt_R04->SetMarkerColor(kMagenta+2); hJetPt_R04->SetMarkerSize(2); 
	hJetEta_R04->SetLineColor(kMagenta+2); hJetEta_R04->SetLineWidth(2);hJetEta_R04->SetMarkerStyle(33); hJetEta_R04->SetMarkerColor(kMagenta+2); hJetEta_R04->SetMarkerSize(2);	
        hJetPhi_R04->SetLineColor(kMagenta+2);

        //Generator level
        hJetPt_R01_gen->SetLineColor(kBlue+2); hJetPt_R01_gen->SetLineWidth(2);hJetPt_R01_gen->SetMarkerStyle(29); hJetPt_R01_gen->SetMarkerColor(kBlue+2);hJetPt_R01_gen->SetMarkerSize(2);
        hJetEta_R01_gen->SetLineColor(kBlue+2); hJetEta_R01_gen->SetLineWidth(2);hJetEta_R01_gen->SetMarkerStyle(29);hJetEta_R01_gen->SetMarkerColor(kBlue+2);hJetEta_R01_gen->SetMarkerSize(2);
        hJetPhi_R01_gen->SetLineColor(kBlue+2);

        hJetPt_R02_gen->SetLineColor(2); hJetPt_R02_gen->SetLineWidth(2);hJetPt_R02_gen->SetMarkerStyle(29);hJetPt_R02_gen->SetMarkerColor(2);hJetPt_R02_gen->SetMarkerSize(2);
        hJetEta_R02_gen->SetLineColor(2); hJetEta_R02_gen->SetLineWidth(2);hJetEta_R02_gen->SetMarkerStyle(29);hJetEta_R02_gen->SetMarkerColor(2);hJetEta_R02_gen->SetMarkerSize(2);
        hJetPhi_R02_gen->SetLineColor(2);

        hJetPt_R03_gen->SetLineColor(kGreen+2); hJetPt_R03_gen->SetLineWidth(2);hJetPt_R03_gen->SetMarkerStyle(29);hJetPt_R03_gen->SetMarkerColor(kGreen+2); hJetPt_R03_gen->SetMarkerSize(2);
        hJetEta_R03_gen->SetLineColor(kGreen+2); hJetEta_R03_gen->SetLineWidth(2);hJetEta_R03_gen->SetMarkerStyle(29); hJetEta_R03_gen->SetMarkerColor(kGreen+2); hJetEta_R03_gen->SetMarkerSize(2);   
        hJetPhi_R03_gen->SetLineColor(kGreen+2);

        hJetPt_R04_gen->SetLineColor(kMagenta+2); hJetPt_R04_gen->SetLineWidth(2);hJetPt_R04_gen->SetMarkerStyle(29); hJetPt_R04_gen->SetMarkerColor(kMagenta+2); hJetPt_R04_gen->SetMarkerSize(2);       
        hJetEta_R04_gen->SetLineColor(kMagenta+2); hJetEta_R04_gen->SetLineWidth(2);hJetEta_R04_gen->SetMarkerStyle(29);hJetEta_R04_gen->SetMarkerColor(kMagenta+2); hJetEta_R04_gen->SetMarkerSize(2); 
        hJetPhi_R04_gen->SetLineColor(kMagenta+2);


	//Matched jet spectra
        //Detector level
        //Matched Jet R=0.1
        hJetPtMatched_R01->SetLineColor(kBlue+2); hJetPtMatched_R01->SetLineWidth(2);
        hJetPtMatched_R01->SetMarkerSize(2);hJetPtMatched_R01->SetMarkerStyle(33);
        hJetPtMatched_R01->SetMarkerColor(kBlue+2);

        //Matched Jet R=0.2
        hJetPtMatched_R02->SetLineColor(2); hJetPtMatched_R02->SetLineWidth(2);
        hJetPtMatched_R02->SetMarkerSize(2); hJetPtMatched_R02->SetMarkerStyle(33);
        hJetPtMatched_R02->SetMarkerColor(2);

        //Matched Jet R=0.3
        hJetPtMatched_R03->SetLineColor(kGreen+2); hJetPtMatched_R03->SetLineWidth(2);
        hJetPtMatched_R03->SetMarkerSize(2); hJetPtMatched_R03->SetMarkerStyle(33);
        hJetPtMatched_R03->SetMarkerColor(kGreen+2);
        
        //Matched Jet R=0.4
        hJetPtMatched_R04->SetLineColor(kMagenta+2); hJetPtMatched_R04->SetLineWidth(2);
        hJetPtMatched_R04->SetMarkerSize(2); hJetPtMatched_R04->SetMarkerStyle(33);
        hJetPtMatched_R04->SetMarkerColor(kMagenta+2);

        //Matched Jet R=0.1
	hJetEtaMatched_R01->SetLineColor(kBlue+2); hJetEtaMatched_R01->SetLineWidth(2);
        hJetEtaMatched_R01->SetMarkerSize(3); hJetEtaMatched_R01->SetMarkerStyle(33);
        hJetEtaMatched_R01->SetMarkerColor(kBlue+2);

        //Matched Jet R=0.2
        hJetEtaMatched_R02->SetLineColor(2); hJetEtaMatched_R02->SetLineWidth(2);
        hJetEtaMatched_R02->SetMarkerSize(3); hJetEtaMatched_R02->SetMarkerStyle(33);
        hJetEtaMatched_R02->SetMarkerColor(2);
        
        //Matched Jet R=0.3
        hJetEtaMatched_R03->SetLineColor(kGreen+2); hJetEtaMatched_R03->SetLineWidth(2);
        hJetEtaMatched_R03->SetMarkerSize(3); hJetEtaMatched_R03->SetMarkerStyle(33);
        hJetEtaMatched_R03->SetMarkerColor(kGreen+2);
        
        //Matched Jet R=0.4
        hJetEtaMatched_R04->SetLineColor(kMagenta+2); hJetEtaMatched_R04->SetLineWidth(2);
        hJetEtaMatched_R04->SetMarkerSize(3); hJetEtaMatched_R04->SetMarkerStyle(33);
        hJetEtaMatched_R04->SetMarkerColor(kMagenta+2);

        //Generator level
        //Matched Jet R=0.1
        hJetPtMatched_R01_gen->SetLineColor(kBlue+2); hJetPtMatched_R01_gen->SetLineWidth(2);
        hJetPtMatched_R01_gen->SetMarkerSize(2); hJetPtMatched_R01_gen->SetMarkerStyle(29);
        hJetPtMatched_R01_gen->SetMarkerColor(kBlue+2);

        //Matched Jet R=0.2
        hJetPtMatched_R02_gen->SetLineColor(2); hJetPtMatched_R02_gen->SetLineWidth(2);
        hJetPtMatched_R02_gen->SetMarkerSize(2); hJetPtMatched_R02_gen->SetMarkerStyle(29);
        hJetPtMatched_R02_gen->SetMarkerColor(2);

        //Matched Jet R=0.3
        hJetPtMatched_R03_gen->SetLineColor(kGreen+2); hJetPtMatched_R03_gen->SetLineWidth(2);
        hJetPtMatched_R03_gen->SetMarkerSize(2); hJetPtMatched_R03_gen->SetMarkerStyle(29);
        hJetPtMatched_R03_gen->SetMarkerColor(kGreen+2);

        //Matched Jet R=0.4
        hJetPtMatched_R04_gen->SetLineColor(kMagenta+2); hJetPtMatched_R04_gen->SetLineWidth(2);
        hJetPtMatched_R04_gen->SetMarkerSize(2); hJetPtMatched_R04_gen->SetMarkerStyle(29);
        hJetPtMatched_R04_gen->SetMarkerColor(kMagenta+2);

        //Matched Jet R=0.1
        hJetEtaMatched_R01_gen->SetLineColor(kBlue+2); hJetEtaMatched_R01_gen->SetLineWidth(2);
        hJetEtaMatched_R01_gen->SetMarkerSize(3); hJetEtaMatched_R01_gen->SetMarkerStyle(29);
        hJetEtaMatched_R01_gen->SetMarkerColor(kBlue+2);

        //Matched Jet R=0.2
        hJetEtaMatched_R02_gen->SetLineColor(2); hJetEtaMatched_R02_gen->SetLineWidth(2);
        hJetEtaMatched_R02_gen->SetMarkerSize(3); hJetEtaMatched_R02_gen->SetMarkerStyle(29);
        hJetEtaMatched_R02_gen->SetMarkerColor(2);

        //Matched Jet R=0.3
        hJetEtaMatched_R03_gen->SetLineColor(kGreen+2); hJetEtaMatched_R03_gen->SetLineWidth(2);
        hJetEtaMatched_R03_gen->SetMarkerSize(3); hJetEtaMatched_R03_gen->SetMarkerStyle(29);
        hJetEtaMatched_R03_gen->SetMarkerColor(kGreen+2);

        //Matched Jet R=0.4
        hJetEtaMatched_R04_gen->SetLineColor(kMagenta+2); hJetEtaMatched_R04_gen->SetLineWidth(2);
        hJetEtaMatched_R04_gen->SetMarkerSize(3); hJetEtaMatched_R04_gen->SetMarkerStyle(29);
        hJetEtaMatched_R04_gen->SetMarkerColor(kMagenta+2);


	//Name and Title manipulation of the spectra retrieved from the jet lists

 	gStyle->SetOptStat(0);
        gStyle->SetTitleFont(42);
        gStyle->SetTitleSize(0.05);
        gStyle->SetTitleSize(0.05,"Y");
        gStyle->SetTitleOffset(0.9,"xy");
 
        //Detector level
	hJetPt_R01->SetName("hJetPt_R01"); hJetPhi_R01->SetName("hJetPhi_R01"); hJetEta_R01->SetName("hJetEta_R01");

	hJetPt_R02->SetName("hJetPt_R02"); hJetPhi_R02->SetName("hJetPhi_R02"); hJetEta_R02->SetName("hJetEta_R02");

        hJetPt_R03->SetName("hJetPt_R03"); hJetPhi_R03->SetName("hJetPhi_R03"); hJetEta_R03->SetName("hJetEta_R03");

	hJetPt_R04->SetName("hJetPt_R04"); hJetPhi_R04->SetName("hJetPhi_R04");	hJetEta_R04->SetName("hJetEta_R04");

	hJetPt_R01->SetTitle("Jet Pt Spectrum (R=0.1) (Detector level)");
	hJetPt_R02->SetTitle("Jet Pt Spectrum (R=0.2) (Detector level)");
	hJetPt_R03->SetTitle("Jet Pt Spectrum (R=0.3) (Detector level)");
	hJetPt_R04->SetTitle("Jet Pt Spectrum (R=0.4) (Detector level)");

	hJetPhi_R01->SetTitle("Jet #Phi distribution (R=0.1) (Detector level)");
        hJetPhi_R02->SetTitle("Jet #phi distribution (R=0.2) (Detector level)");
	hJetPhi_R03->SetTitle("Jet #phi distribution (R=0.3) (Detector level)");
	hJetPhi_R04->SetTitle("Jet #phi distribution (R=0.4) (Detector level)");
	
	hJetEta_R01->SetTitle("Jet #eta distribution (R=0.1) (Detector level)");
        hJetEta_R02->SetTitle("Jet #eta distribution (R=0.2) (Detector level)");
	hJetEta_R03->SetTitle("Jet #eta distribution (R=0.3) (Detector level)");
	hJetEta_R04->SetTitle("Jet #eta distribution (R=0.4) (Detector level)");

        //Generator level
        hJetPt_R01_gen->SetName("hJetPt_R01_gen"); hJetPhi_R01_gen->SetName("hJetPhi_R01_gen"); hJetEta_R01_gen->SetName("hJetEta_R01_gen");

        hJetPt_R02_gen->SetName("hJetPt_R02_gen"); hJetPhi_R02_gen->SetName("hJetPhi_R02_gen"); hJetEta_R02_gen->SetName("hJetEta_R02_gen");

        hJetPt_R03_gen->SetName("hJetPt_R03_gen"); hJetPhi_R03_gen->SetName("hJetPhi_R03_gen"); hJetEta_R03_gen->SetName("hJetEta_R03_gen");

        hJetPt_R04_gen->SetName("hJetPt_R04_gen"); hJetPhi_R04_gen->SetName("hJetPhi_R04_gen"); hJetEta_R04_gen->SetName("hJetEta_R04_gen");

        hJetPt_R01_gen->SetTitle("Jet Pt Spectrum (R=0.1) (Generator level)");
        hJetPt_R02_gen->SetTitle("Jet Pt Spectrum (R=0.2) (Generator level)");
        hJetPt_R03_gen->SetTitle("Jet Pt Spectrum (R=0.3) (Generator level)");
        hJetPt_R04_gen->SetTitle("Jet Pt Spectrum (R=0.4) (Generator level)");

        hJetPhi_R01_gen->SetTitle("Jet #Phi distribution (R=0.1) (Generator level)");
        hJetPhi_R02_gen->SetTitle("Jet #phi distribution (R=0.2) (Generator level)");
        hJetPhi_R03_gen->SetTitle("Jet #phi distribution (R=0.3) (Generator level)");
        hJetPhi_R04_gen->SetTitle("Jet #phi distribution (R=0.4) (Generator level)");

        hJetEta_R01_gen->SetTitle("Jet #eta distribution (R=0.1) (Generator level)");
        hJetEta_R02_gen->SetTitle("Jet #eta distribution (R=0.2) (Generator level)");
        hJetEta_R03_gen->SetTitle("Jet #eta distribution (R=0.3) (Generator level)");
        hJetEta_R04_gen->SetTitle("Jet #eta distribution (R=0.4) (Generator level)");
/*
        //Response matrix plots           
        TCanvas *RMDptR01 = new TCanvas("RMDptR01","Dpt Response matrix R01 ",1000,1000);
        RM_pro_R01->SetYTitle("#DeltaP_{t} (Detector level)");
        RM_pro_R01->SetTitle(TString::Format("Response matrix for R=0.1 for jet pt[%d,%d] GeV/c",Ptlow,Pthigh));
        RM_pro_R01->Draw("colz");
        TCanvas *RMDptR02 = new TCanvas("RMDptR02","Dpt Response matrix R02 ",1000,1000);
        RM_pro_R02->SetYTitle("#DeltaP_{t} (Detector level)");
        RM_pro_R02->SetTitle(TString::Format("Response matrix for R=0.2 for jet pt[%d,%d] GeV/c",Ptlow,Pthigh));
        RM_pro_R02->Draw("colz");
        TCanvas *RMDptR03 = new TCanvas("RMDptR03","Dpt Response matrix R03 ",1000,1000);
        RM_pro_R03->SetTitle(TString::Format("Response matrix for R=0.3 for jet pt[%d,%d] GeV/c",Ptlow,Pthigh));
        RM_pro_R03->SetYTitle("#DeltaP_{t} (Detector level)");
        RM_pro_R03->Draw("colz");
        
	//Projections calculation

//--------------- Commenting this section our until the Filling of Deta plots is fixed	
	//Dpt vs DEta projections
        //Detector level
	hDeltaPtvPtvDeltaEta_R10->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R01_Deta= hDeltaPtvPtvDeltaEta_R10->Project3D("zx");
        hDeltaPtvPtvDeltaEta_R20->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_Deta= hDeltaPtvPtvDeltaEta_R20->Project3D("zx");
        hDeltaPtvPtvDeltaEta_R30->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_Deta= hDeltaPtvPtvDeltaEta_R30->Project3D("zx");
        
        //Jet R=0.1
	TCanvas *DEta1 = new TCanvas("DEta1","Dpt vs DEta R01 (Detector level)",1000,1000);
        pro_R01_Deta->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.1 and R=0.2 [%d,%d]GeV/c (Detector level)",Ptlow_bin,Pthigh_bin));
        pro_R01_Deta->Draw("colz");
        
        //Jet R=0.2
	TCanvas *DEta2 = new TCanvas("DEta2","Dpt vs DEta R02 (Detector level)",1000,1000);
        pro_R02_Deta->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.2 and R=0.3 [%d,%d]GeV/c (Detector level)",Ptlow_bin,Pthigh_bin));
        pro_R02_Deta->Draw("colz");
        
        //Jet R=0.3
	TCanvas *DEta3 = new TCanvas("DEta3","Dpt vs DEta R03 (Detector level)",1000,1000);
        pro_R03_Deta->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.3 and R=0.4 [%d,%d]GeV/c (Detector level)",Ptlow_bin,Pthigh_bin));
        pro_R03_Deta->Draw("colz");

        //Generator level
        hDeltaPtvPtvDeltaEta_R10_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R01_Deta_gen= hDeltaPtvPtvDeltaEta_R10_gen->Project3D("zx");
        hDeltaPtvPtvDeltaEta_R20_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_Deta_gen= hDeltaPtvPtvDeltaEta_R20_gen->Project3D("zx");
        hDeltaPtvPtvDeltaEta_R30_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_Deta_gen= hDeltaPtvPtvDeltaEta_R30_gen->Project3D("zx");

        //Jet R=0.1
        TCanvas *DEta1gen = new TCanvas("DEta1_GEN","Dpt vs DEta R01 (Generator level)",1000,1000);
        pro_R01_Deta_gen->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.1 and R=0.2 [%d,%d]GeV/c Generator level)",Ptlow_bin,Pthigh_bin));
        pro_R01_Deta_gen->Draw("colz");

        //Jet R=0.2
        TCanvas *DEta2_gen = new TCanvas("DEta2_GEN","Dpt vs DEta R02 (Generator level)",1000,1000);
        pro_R02_Deta_gen->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.2 and R=0.3 [%d,%d]GeV/c (Generator level)",Ptlow_bin,Pthigh_bin));
        pro_R02_Deta_gen->Draw("colz");

        //Jet R=0.3
        TCanvas *DEta3gen = new TCanvas("DEta3_GEN","Dpt vs DEta R03 (Generator level)",1000,1000);
        pro_R03_Deta_gen->SetTitle(TString::Format("#DeltaP_{t} vs #Delta#eta between R=0.3 and R=0.4 [%d,%d]GeV/c (Generator level)",Ptlow_bin,Pthigh_bin));
        pro_R03_Deta_gen->Draw("colz");



	//Dpt  vs DR projections
        //Detector level
	hJetPtDeltaRDeltaPt_R10->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
	TH1* pro_R01_deltas=hJetPtDeltaRDeltaPt_R10->Project3D("zy");
	hJetPtDeltaRDeltaPt_R20->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_deltas=hJetPtDeltaRDeltaPt_R20->Project3D("zy");
        hJetPtDeltaRDeltaPt_R30->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_deltas=hJetPtDeltaRDeltaPt_R30->Project3D("zy");
        
        //Jet R=0.1
        TCanvas *Delta1 = new TCanvas("Delta1","Dpt vs DR R01 (Detector level)",1000,1000);
        pro_R01_deltas->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.1 and R=0.2 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
        pro_R01_deltas->Draw("colz");
        
        //Jet R=0.2
        TCanvas *Delta2 = new TCanvas("Delta2","Dpt vs DR R02 (Detector level)",1000,1000);
        pro_R02_deltas->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.2 and R=0.3 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
        pro_R02_deltas->Draw("colz");
       
         //Jet R=0.3
        TCanvas *Delta3 = new TCanvas("Delta3","Dpt vs DR R03 (Detector level)",1000,1000);
        pro_R03_deltas->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.3 and R=0.4 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
        pro_R03_deltas->Draw("colz");

        //Generator level
        hJetPtDeltaRDeltaPt_R10_gen->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R01_deltas_gen=hJetPtDeltaRDeltaPt_R10_gen->Project3D("zy");
        hJetPtDeltaRDeltaPt_R20_gen->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_deltas_gen=hJetPtDeltaRDeltaPt_R20_gen->Project3D("zy");
        hJetPtDeltaRDeltaPt_R30_gen->GetXaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_deltas_gen=hJetPtDeltaRDeltaPt_R30_gen->Project3D("zy");

        //Jet R=0.1
        TCanvas *Delta1_gen = new TCanvas("Delta1_GEN","Dpt vs DR R01 (Generator level)",1000,1000);
        pro_R01_deltas_gen->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.1 and R=0.2 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R01_deltas_gen->Draw("colz");

        //Jet R=0.2
        TCanvas *Delta2_gen = new TCanvas("Delta2_GEN","Dpt vs DR R02 (Generator level)",1000,1000);
        pro_R02_deltas_gen->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.2 and R=0.3 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R02_deltas_gen->Draw("colz");

         //Jet R=0.3
        TCanvas *Delta3_gen = new TCanvas("Delta3_GEN","Dpt vs DR R03 (Generator level)",1000,1000);
        pro_R03_deltas_gen->SetTitle(TString::Format("#DeltaP_{t} vs #DeltaR between R=0.3 and R=0.4 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R03_deltas_gen->Draw("colz");
*/

	//Dpt vs multiplicity
	//Detector level
        hDeltaPtvPtvMultiplicity_R10->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
	TH1* pro_R01_mult = hDeltaPtvPtvMultiplicity_R10->Project3D("zx");
        hDeltaPtvPtvMultiplicity_R20->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_mult = hDeltaPtvPtvMultiplicity_R20->Project3D("zx");
        hDeltaPtvPtvMultiplicity_R30->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_mult = hDeltaPtvPtvMultiplicity_R30->Project3D("zx");

        //Jet R=0.1
        TCanvas *mult1 = new TCanvas("mult1","Dpt vs Multiplicity R01 (Detector level)",1000,1000);
	pro_R01_mult->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.1 and R=0.2 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
	pro_R01_mult->Draw("colz");
        mult1->SaveAs(Form("./EnergyFlow_plots/DptvMulti_det_R01_%d_%d_ppmc.png",Ptlow,Pthigh));
        
        //Jet R=0.2
       	TCanvas *mult2 = new TCanvas("mult2","Dpt vs Multiplicity R02 (Detector level)",1000,1000);
        pro_R02_mult->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.2 and R=0.3 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
        pro_R02_mult->Draw("colz");
        mult2->SaveAs(Form("./EnergyFlow_plots/DptvMulti_det_R02_%d_%d_ppmc.png",Ptlow,Pthigh));

        //Jet R=0.3
        TCanvas *mult3 = new TCanvas("mult3","Dpt vs Multiplicity R03 (Detector level)",1000,1000);
        pro_R03_mult->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.3 and R=0.4 [%d,%d]GeV/c (Detector level)",Ptlow,Pthigh));
        pro_R03_mult->Draw("colz");
        mult3->SaveAs(Form("./EnergyFlow_plots/DptvMulti_det_R03_%d_%d_ppmc.png",Ptlow,Pthigh));

        //Generator level
        hDeltaPtvPtvMultiplicity_R10_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R01_mult_gen = hDeltaPtvPtvMultiplicity_R10_gen->Project3D("zx");
        hDeltaPtvPtvMultiplicity_R20_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R02_mult_gen = hDeltaPtvPtvMultiplicity_R20_gen->Project3D("zx");
        hDeltaPtvPtvMultiplicity_R30_gen->GetYaxis()->SetRange(Ptlow_bin,Pthigh_bin);
        TH1* pro_R03_mult_gen = hDeltaPtvPtvMultiplicity_R30_gen->Project3D("zx");

        //Jet R=0.1
        TCanvas *mult1_gen = new TCanvas("mult1_GEN","Dpt vs Multiplicity R01 (Generator level)",1000,1000);
        pro_R01_mult_gen->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.1 and R=0.2 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R01_mult_gen->Draw("colz");
        mult1_gen->SaveAs(Form("./EnergyFlow_plots/DptvMulti_gen_R01_%d_%d_ppmc.png",Ptlow,Pthigh));

        //Jet R=0.2
        TCanvas *mult2_gen = new TCanvas("mult2_GEN","Dpt vs Multiplicity R02 (Generator level)",1000,1000);
        pro_R02_mult_gen->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.2 and R=0.3 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R02_mult_gen->Draw("colz");
        mult2_gen->SaveAs(Form("./EnergyFlow_plots/DptvMulti_gen_R02_%d_%d_ppmc.png",Ptlow,Pthigh));

        //Jet R=0.3
        TCanvas *mult3_gen = new TCanvas("mult3_GEN","Dpt vs Multiplicity R03 (Generator level)",1000,1000);
        pro_R03_mult_gen->SetTitle(TString::Format("Multiplicity vs #DeltaP_{t} projection between R=0.3 and R=0.4 [%d,%d]GeV/c (Generator level)",Ptlow,Pthigh));
        pro_R03_mult_gen->Draw("colz");
        mult3_gen->SaveAs(Form("./EnergyFlow_plots/DptvMulti_gen_R03_%d_%d_ppmc.png",Ptlow,Pthigh));
/*
	//DR vs eta
	TCanvas *DReta1 = new TCanvas("DReta1","DR vs eta R01",1000,1000);
	hEtaJetDeltaR_R10->Draw("colz");

	TCanvas *DReta2 = new TCanvas("DReta2","DR vs eta R02",1000,1000);
        hEtaJetDeltaR_R20->Draw("colz");

	TCanvas *DReta3 = new TCanvas("DReta3","DR vs eta R03",1000,1000);
        hEtaJetDeltaR_R30->Draw("colz");
*/
        //Detector level
	//Dpt projections
        
	TH1D*pro_R01 = hDptR01->ProjectionY("pro_R01",Ptlow_bin,Pthigh_bin);
//	pro_R01->Sumw2();
	TH1D*pro_R02 = hDptR02->ProjectionY("pro_R02",Ptlow_bin,Pthigh_bin);
//	pro_R02->Sumw2();
	TH1D*pro_R03 = hDptR03->ProjectionY("pro_R03",Ptlow_bin,Pthigh_bin);
//	pro_R03->Sumw2();

	//DR projections
	TH1D*pro_DR01 = hDR01->ProjectionY("pro_DR01",Ptlow_bin,Pthigh_bin);
  //      pro_DR01->Sumw2();
	TH1D*pro_DR02 = hDR02->ProjectionY("pro_DR02",Ptlow_bin,Pthigh_bin);
    //    pro_DR02->Sumw2();
	TH1D*pro_DR03 = hDR03->ProjectionY("pro_DR03",Ptlow_bin,Pthigh_bin);
//	pro_DR03->Sumw2();

	pro_R01->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.1 and R=0.2 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));
	pro_R02->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.2 and R=0.3 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));
	pro_R03->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.3 and R=0.4 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));

	pro_DR01->SetTitle(TString::Format("#DeltaR projection between R=0.1 and R=0.2 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));
        pro_DR02->SetTitle(TString::Format("#DeltaR projection between R=0.2 and R=0.3 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));
        pro_DR03->SetTitle(TString::Format("#DeltaR projection between R=0.3 and R=0.4 [%d,%d] (GeV/c) (Detector level)",Ptlow,Pthigh));

	//Jet R=0.1
	pro_R01->SetLineColor(kBlue+2);	pro_R01->SetLineWidth(2);
	pro_DR01->SetLineColor(kBlue+2); pro_DR01->SetLineWidth(2);
        pro_R01->SetMarkerSize(3); pro_DR01->SetMarkerSize(3);
        pro_DR01->SetMarkerStyle(33); pro_R01->SetMarkerStyle(33);
        pro_R01->SetMarkerColor(kBlue+2); pro_DR01->SetMarkerColor(kBlue+2);

        //Jet R=0.2
	pro_R02->SetLineColor(2); pro_R02->SetLineWidth(2);
	pro_DR02->SetLineColor(2); pro_DR02->SetLineWidth(2);
        pro_R02->SetMarkerSize(3); pro_R02->SetMarkerStyle(33);
        pro_DR02->SetMarkerStyle(33); pro_DR02->SetMarkerSize(3);
        pro_R02->SetMarkerColor(2); pro_DR02->SetMarkerColor(2);
	
        //Jet R=0.3
	pro_R03->SetLineColor(kGreen+2); pro_R03->SetLineWidth(2);
	pro_DR03->SetLineColor(kGreen+2); pro_DR03->SetLineWidth(2);
        pro_R03->SetMarkerSize(3); pro_R03->SetMarkerStyle(33);
        pro_DR03->SetMarkerStyle(33); pro_DR03->SetMarkerSize(3);
        pro_R03->SetMarkerColor(kGreen+2); pro_DR03->SetMarkerColor(kGreen+2);

        //Generator level
        //Dpt projections
        TH1D*pro_R01_gen = hDptR01_gen->ProjectionY("pro_R01_gen",Ptlow_bin,Pthigh_bin);
  //      pro_R01_gen->Sumw2();
        TH1D*pro_R02_gen = hDptR02_gen->ProjectionY("pro_R02_gen",Ptlow_bin,Pthigh_bin);
  //      pro_R02_gen->Sumw2();
        TH1D*pro_R03_gen = hDptR03_gen->ProjectionY("pro_R03_gen",Ptlow_bin,Pthigh_bin);
  //      pro_R03_gen->Sumw2();

        //DR projections
        TH1D*pro_DR01_gen = hDR01_gen->ProjectionY("pro_DR01_gen",Ptlow_bin,Pthigh_bin);
 //       pro_DR01_gen->Sumw2();
        TH1D*pro_DR02_gen = hDR02_gen->ProjectionY("pro_DR02_gen",Ptlow_bin,Pthigh_bin);
  //      pro_DR02_gen->Sumw2();
        TH1D*pro_DR03_gen = hDR03_gen->ProjectionY("pro_DR03_gen",Ptlow_bin,Pthigh_bin);
  //      pro_DR03_gen->Sumw2();

        pro_R01_gen->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.1 and R=0.2 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));
        pro_R02_gen->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.2 and R=0.3 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));
        pro_R03_gen->SetTitle(TString::Format("#DeltaP_{t} projection between R=0.3 and R=0.4 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));

        pro_DR01_gen->SetTitle(TString::Format("#DeltaR projection between R=0.1 and R=0.2 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));
        pro_DR02_gen->SetTitle(TString::Format("#DeltaR projection between R=0.2 and R=0.3 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));
        pro_DR03_gen->SetTitle(TString::Format("#DeltaR projection between R=0.3 and R=0.4 [%d,%d] (GeV/c) (Generator level)",Ptlow,Pthigh));

        //Jet R=0.1
        pro_R01_gen->SetLineColor(kBlue+2); pro_R01_gen->SetLineWidth(2);
        pro_DR01_gen->SetLineColor(kBlue+2); pro_DR01_gen->SetLineWidth(2);
        pro_R01_gen->SetMarkerSize(3); pro_DR01_gen->SetMarkerSize(3);
        pro_DR01_gen->SetMarkerStyle(29); pro_R01_gen->SetMarkerStyle(29);
        pro_R01_gen->SetMarkerColor(kBlue+2); pro_DR01_gen->SetMarkerColor(kBlue+2);

        //Jet R=0.2
        pro_R02_gen->SetLineColor(2); pro_R02_gen->SetLineWidth(2);
        pro_DR02_gen->SetLineColor(2); pro_DR02_gen->SetLineWidth(2);
        pro_R02_gen->SetMarkerSize(3); pro_R02_gen->SetMarkerStyle(29);
        pro_DR02_gen->SetMarkerStyle(29); pro_DR02_gen->SetMarkerSize(3);
        pro_R02_gen->SetMarkerColor(2); pro_DR02_gen->SetMarkerColor(2);

        //Jet R=0.3
        pro_R03_gen->SetLineColor(kGreen+2); pro_R03_gen->SetLineWidth(2);
        pro_DR03_gen->SetLineColor(kGreen+2); pro_DR03_gen->SetLineWidth(2);
        pro_R03_gen->SetMarkerSize(3); pro_R03_gen->SetMarkerStyle(29);
        pro_DR03_gen->SetMarkerStyle(29); pro_DR03_gen->SetMarkerSize(3);
        pro_R03_gen->SetMarkerColor(kGreen+2); pro_DR03_gen->SetMarkerColor(kGreen+2);

	//Histogram normalization
	//Detector level
	pro_R01->Scale(1/pro_R01->Integral());
	pro_R02->Scale(1/pro_R02->Integral());
	pro_R03->Scale(1/pro_R03->Integral());

	pro_DR01->Scale(1/pro_DR01->Integral());
	pro_DR02->Scale(1/pro_DR02->Integral());
	pro_DR03->Scale(1/pro_DR03->Integral());

        //Generator level
        pro_R01_gen->Scale(1/pro_R01_gen->Integral());
        pro_R02_gen->Scale(1/pro_R02_gen->Integral());
        pro_R03_gen->Scale(1/pro_R03_gen->Integral());

        pro_DR01_gen->Scale(1/pro_DR01_gen->Integral());
        pro_DR02_gen->Scale(1/pro_DR02_gen->Integral());
        pro_DR03_gen->Scale(1/pro_DR03_gen->Integral());

	//Mean and RMS calculation
	Double_t R[3] = {.1,.2,.3};
        Double_t R_err[3] = {0,0,0};
        //Detector level
	Double_t mean[3] ={pro_R01->GetMean(),pro_R02->GetMean(),pro_R03->GetMean()};
	Double_t RMS[3] = {pro_R01->GetRMS(),pro_R02->GetRMS(),pro_R03->GetRMS()};
	Double_t mean_err[3] = {pro_R01->GetMeanError(),pro_R02->GetMeanError(),pro_R03->GetMeanError()};
	Double_t RMS_err[3] = {pro_R01->GetRMSError(),pro_R02->GetRMSError(),pro_R03->GetRMSError()};
        
        //Generator level
	
        Double_t mean_gen[3] ={pro_R01_gen->GetMean(),pro_R02_gen->GetMean(),pro_R03_gen->GetMean()};
        Double_t RMS_gen[3] = {pro_R01_gen->GetRMS(),pro_R02_gen->GetRMS(),pro_R03_gen->GetRMS()};
        Double_t mean_err_gen[3] = {pro_R01_gen->GetMeanError(),pro_R02_gen->GetMeanError(),pro_R03_gen->GetMeanError()};
        Double_t RMS_err_gen[3] = {pro_R01_gen->GetRMSError(),pro_R02_gen->GetRMSError(),pro_R03_gen->GetRMSError()};

	auto Mean_gr = new TGraphErrors(3,R,mean,R_err,mean_err);
	Mean_gr->SetMarkerSize(3);
	Mean_gr->SetMarkerStyle(33);
	Mean_gr->SetTitle(TString::Format("Mean of the #DeltaP_{t} projection distributions [%d,%d] (Detector level);R_{low}; Mean value",Ptlow,Pthigh));

	auto RMS_gr = new TGraphErrors(3,R,RMS,R_err,RMS_err);
        RMS_gr->SetMarkerSize(3);
        RMS_gr->SetMarkerStyle(33);
	RMS_gr->SetTitle(TString::Format("RMS of the #DeltaP_{t} projection distributions [%d,%d] (Detector level);R_{low}; RMS value",Ptlow,Pthigh));

        auto Mean_gr_gen = new TGraphErrors(3,R,mean_gen,R_err,mean_err_gen);
        Mean_gr_gen->SetMarkerSize(3);
        Mean_gr_gen->SetMarkerStyle(29);
        Mean_gr_gen->SetTitle(TString::Format("Mean of the #DeltaP_{t} projection distributions [%d,%d] (Generator level);R_{low}; Mean value",Ptlow,Pthigh));

        auto RMS_gr_gen = new TGraphErrors(3,R,RMS_gen,R_err,RMS_err_gen);
        RMS_gr_gen->SetMarkerSize(3);
        RMS_gr_gen->SetMarkerStyle(29);
        RMS_gr_gen->SetTitle(TString::Format("RMS of the #DeltaP_{t} projection distributions [%d,%d] (Generator level);R_{low}; RMS value",Ptlow,Pthigh));

//-------------------------Plotting section

		// Jet spectra plot
		
                //Detector level
                // Pt spectrum
                TCanvas*c1 = new TCanvas("c1","Jet P_{t} spectra overview (Detector level)",1200,1200);
		c1->SetLogy(1);
	//	hJetPt_R01->SetMaximum(1.2);
		hJetPt_R01->Draw();
		hJetPt_R02->Draw("same");
		hJetPt_R03->Draw("same");
		hJetPt_R04->Draw("same");

		auto legend1 = new TLegend(.7,.8,.9,.9);
		legend1->AddEntry(hJetPt_R01,"R = 0.1","p");
		legend1->AddEntry(hJetPt_R02,"R = 0.2","p");
		legend1->AddEntry(hJetPt_R03,"R = 0.3","p");
		legend1->AddEntry(hJetPt_R04,"R = 0.4","p");
		legend1->Draw();
                c1->SetGridy(1);
//                c1->SaveAs("./EnergyFlow_plots/Jet_ptspectrum_detLevel_ppmc.png");   

                //Eta distribution
                TCanvas*c1a = new TCanvas("c1a","Jet #eta distribution overview (Detector level)",1200,1200);
                hJetEta_R01->Draw();
                hJetEta_R02->Draw("same");
                hJetEta_R03->Draw("same");
                hJetEta_R04->Draw("same");
		legend1->Draw();
                c1a->SetGridy(1);
         //       c1a->SaveAs("./EnergyFlow_plots/Jet_etadist_detLevel_ppmc.png");

                //Matched jet pt spectrum
	     	TCanvas *c1b = new TCanvas("c1b","Matched jet Pt spectra (Detector level)",1200,1200);
       		c1b->SetLogy(1);
        //	hJetPtMatched_R01->SetMaximum(1.2);
        	hJetPtMatched_R01->Draw();
        	hJetPtMatched_R02->Draw("same");
        	hJetPtMatched_R03->Draw("same");
        	hJetPtMatched_R04->Draw("same");
        	legend1->Draw();
                c1b->SetGridy(1);
        //        c1b->SaveAs("./EnergyFlow_plots/Matchedjet_ptspectrum_detLevel_ppmc.png");

                //Matched jet eta distribution
       	 	TCanvas *c1c = new TCanvas("c1c","Matched jet Eta distribution (Detector level)",1200,1200);
        	hJetEtaMatched_R01->Draw();
        	hJetEtaMatched_R02->Draw("same");
        	hJetEtaMatched_R03->Draw("same");
        	hJetEtaMatched_R04->Draw("same");
        	legend1->Draw();
                c1c->SetGridy(1);
        //        c1c->SaveAs("./EnergyFlow_plots/Matchedjet_etadist_detLevel_ppmc.png");
                
                //Generator level
                // Pt spectrum
                TCanvas*c1_gen = new TCanvas("c1_GEN","Jet P_{t} spectra overview (Generator level)",1200,1200);
                c1_gen->SetLogy(1);
        //      hJetPt_R01->SetMaximum(1.2);
                hJetPt_R01_gen->Draw();
                hJetPt_R02_gen->Draw("same");
                hJetPt_R03_gen->Draw("same");
                hJetPt_R04_gen->Draw("same");
                
                auto legend1a = new TLegend(.7,.8,.9,.9);
                legend1a->AddEntry(hJetPt_R01_gen,"R = 0.1","p");
                legend1a->AddEntry(hJetPt_R02_gen,"R = 0.2","p");
                legend1a->AddEntry(hJetPt_R03_gen,"R = 0.3","p");
                legend1a->AddEntry(hJetPt_R04_gen,"R = 0.4","p");
                legend1a->Draw();
                c1_gen->SetGridy(1);
     //         c1_gen->SaveAs("./EnergyFlow_plots/Jet_ptspectrum_genLevel_ppmc.png");

                //Eta distribution
                TCanvas*c1a_gen = new TCanvas("c1a_GEN","Jet #eta distribution overview (Generator level)",1200,1200);
                hJetEta_R01_gen->Draw();
                hJetEta_R02_gen->Draw("same");
                hJetEta_R03_gen->Draw("same");
                hJetEta_R04_gen->Draw("same");
                legend1a->Draw();
                c1a_gen->SetGridy(1);
     //         c1a_gen->SaveAs("./EnergyFlow_plots/Jet_etadist_genLevel_ppmc.png");                

                //Matched jet pt spectrum
                TCanvas *c1b_gen = new TCanvas("c1b_GEN","Matched jet Pt spectra (Generator level)",1200,1200);
                c1b_gen->SetLogy(1);
        //      hJetPtMatched_R01->SetMaximum(1.2);
                hJetPtMatched_R01_gen->Draw();
                hJetPtMatched_R02_gen->Draw("same");
                hJetPtMatched_R03_gen->Draw("same");
                hJetPtMatched_R04_gen->Draw("same");
                legend1a->Draw();
                c1b_gen->SetGridy(1);
     //         c1b_gen->SaveAs("./EnergyFlow_plots/Matchedjet_ptspectrum_genLevel_ppmc.png");                

                //Matched jet eta distribution
                TCanvas *c1c_gen = new TCanvas("c1c_GEN","Matched jet Eta distribution (Generator level)",1200,1200);
                hJetEtaMatched_R01_gen->Draw();
                hJetEtaMatched_R02_gen->Draw("same");
                hJetEtaMatched_R03_gen->Draw("same");
                hJetEtaMatched_R04_gen->Draw("same");
                legend1a->Draw();
                c1c_gen->SetGridy(1);
   //           c1c_gen->SaveAs("./EnergyFlow_plots/Matchedjet_etadist_genLevel_ppmc.png");

		// Delta Pt projections plots
		//Detector level
                TCanvas*c2 = new TCanvas("c2","DeltaPt projections overview (Detector level)",1200,1200);
		c2->SetLogy(1);
		c2->DrawFrame(-20,1e-8,30,10,TString::Format("#DeltaP_{t} projection overview [%d,%d](GeV/c) (Detector level);#DeltaP_{t} (GeV/c)",Ptlow,Pthigh));
//                pro_R01->SetMaximum(.8);
//		pro_R01->SetAxisRange(-20,30,"X");
		pro_R01->Draw("same");
		pro_R02->Draw("same");
		pro_R03->Draw("same");

		auto legend2 = new TLegend(.7,.8,.9,.9);
                legend2->AddEntry(pro_R01,"R = 0.1 to R = 0.2","p");
                legend2->AddEntry(pro_R02,"R = 0.2 to R = 0.3","p");
                legend2->AddEntry(pro_R03,"R = 0.3 to R = 0.4","p");
                legend2->Draw();
                c2->SetGridy(1);
                c2->SaveAs(Form("./EnergyFlow_plots/Dpt_pro_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));                

		TCanvas*c3 = new TCanvas("c3","DeltaR projections overview (Detector level)",1200,1200);
                c3->DrawFrame(0,0,0.4,1,TString::Format("#DeltaR projection overview [%d,%d](GeV/c) (Detector level);#DeltaR",Ptlow,Pthigh));
                //pro_DR01->SetMaximum(.9);
                pro_DR01->Draw("same");
                pro_DR02->Draw("same");
                pro_DR03->Draw("same");
		legend2->Draw();
                c3->SetGridy(1);
                c3->SaveAs(Form("./EnergyFlow_plots/DR_pro_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));

                //Generator level
                TCanvas*c2_gen = new TCanvas("c2_GEN","DeltaPt projections overview (Generator level)",1200,1200);
                c2_gen->SetLogy(1);
                c2_gen->DrawFrame(-20,1e-8,30,10,TString::Format("#DeltaP_{t} projection overview [%d,%d](GeV/c) (Generator level);#DeltaP_{t} (GeV/c)",Ptlow,Pthigh));
           //     pro_R01_gen->SetMaximum(.8);
           //     pro_R01_gen->SetAxisRange(-20,30,"X");
                pro_R01_gen->Draw("same");
                pro_R02_gen->Draw("same");
                pro_R03_gen->Draw("same");

                auto legend2a = new TLegend(.7,.8,.9,.9);
                legend2a->AddEntry(pro_R01_gen,"R = 0.1 to R = 0.2","p");
                legend2a->AddEntry(pro_R02_gen,"R = 0.2 to R = 0.3","p");
                legend2a->AddEntry(pro_R03_gen,"R = 0.3 to R = 0.4","p");
                legend2a->Draw();
                c2_gen->SetGridy(1);
                c2_gen->SaveAs(Form("./EnergyFlow_plots/Dpt_pro_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));

                TCanvas*c3_gen = new TCanvas("c3_GEN","DeltaR projections overview (Generator level)",1200,1200);
           //     pro_DR01_gen->SetMaximum(.9);
                c3_gen->DrawFrame(0,0,0.4,1,TString::Format("#DeltaR projection overview [%d,%d](GeV/c) (Generator level);#DeltaR",Ptlow,Pthigh));
                pro_DR01_gen->Draw("same");
                pro_DR02_gen->Draw("same");
                pro_DR03_gen->Draw("same");
                legend2a->Draw();
                c3_gen->SetGridy(1);
                c3_gen->SaveAs(Form("./EnergyFlow_plots/DR_pro_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));

		//Mean and RMS plots
                //Detector level
		TCanvas*c4 = new TCanvas("c4","Dpt projection Mean (Detector level)",1200,1200);
		c4->DrawFrame(0,0,.5,15,Mean_gr->GetTitle());
		Mean_gr->Draw("LP");
                c4->SetGridy(1);
                c4->SaveAs(Form("./EnergyFlow_plots/Mean_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));

		TCanvas*c4a = new TCanvas("c4a","Dpt projection RMS (Detector level)",1200,1200);
                c4a->DrawFrame(0,0,.5,15,RMS_gr->GetTitle());
	       	RMS_gr->Draw("LP");
                c4a->SetGridy(1);
                c4a->SaveAs(Form("./EnergyFlow_plots/RMS_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));

                //Generator level
                TCanvas*c4_gen = new TCanvas("c4_GEN","Dpt projection Mean (Generator level)",1200,1200);
                c4_gen->DrawFrame(0,0,.5,15,Mean_gr_gen->GetTitle());
                Mean_gr_gen->Draw("LP");
                c4_gen->SetGridy(1);
                c4_gen->SaveAs(Form("./EnergyFlow_plots/Mean_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));

                TCanvas*c4a_gen = new TCanvas("c4a_GEN","Dpt projection RMS (Generator level)",1200,1200);
                c4a_gen->DrawFrame(0,0,.5,15,RMS_gr_gen->GetTitle());
                RMS_gr_gen->Draw("LP");
                c4a_gen->SetGridy(1);
                c4a_gen->SaveAs(Form("./EnergyFlow_plots/RMS_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));

//------------------------Writing the output to a new file
	TFile*sum = new TFile(TString::Format("EnergyFlow_summary_%d_%d_ppmctrain.root",Ptlow,Pthigh),"RECREATE",TString::Format("EnergyFlow_summary_%d_%d_ppmctrain.root",Ptlow,Pthigh));
	sum->cd();

//	hEtaJetDeltaR_R10->Write(); hEtaJetDeltaR_R20->Write();hEtaJetDeltaR_R30->Write();

	pro_R01_mult->Write(); pro_R02_mult->Write(); pro_R03_mult->Write();
        pro_R01_mult_gen->Write(); pro_R02_mult_gen->Write(); pro_R03_mult_gen->Write();

//	pro_R01_deltas->Write(); pro_R02_deltas->Write(); pro_R03_deltas->Write();
//      pro_R01_deltas_gen->Write(); pro_R02_deltas_gen->Write(); pro_R03_deltas_gen->Write();

//--------------- Commenting this section our until the Filling of Deta plots is fixed
//	pro_R01_Deta->Write(); pro_R02_Deta->Write(); pro_R03_Deta->Write();
//        pro_R01_Deta_gen->Write(); pro_R02_Deta_gen->Write(); pro_R03_Deta_gen->Write();

	hDR01->Write();	hDR02->Write();	hDR03->Write();
        hDR01_gen->Write(); hDR02_gen->Write(); hDR03_gen->Write();

	RMS_gr->Write(TString::Format("RMS_graph_%d_%d",Ptlow,Pthigh));
	Mean_gr->Write(TString::Format("Mean_graph_%d_%d",Ptlow,Pthigh));
        RMS_gr_gen->Write(TString::Format("RMS_graph_gen_%d_%d",Ptlow,Pthigh));
        Mean_gr_gen->Write(TString::Format("Mean_graph_gen_%d_%d",Ptlow,Pthigh));

	hDptR01->Write(); hDptR02->Write(); hDptR03->Write();
        hDptR01_gen->Write(); hDptR02_gen->Write(); hDptR03_gen->Write();
	
	pro_R01->Write(); pro_R02->Write(); pro_R03->Write();
        pro_R01_gen->Write(); pro_R02_gen->Write(); pro_R03_gen->Write();

	pro_DR01->Write(); pro_DR02->Write(); pro_DR03->Write();
        pro_DR01_gen->Write(); pro_DR02_gen->Write(); pro_DR03_gen->Write();

	hJetPt_R01->Write(); hJetEta_R01->Write(); hJetPhi_R01->Write();
        hJetPt_R01_gen->Write(); hJetEta_R01_gen->Write(); hJetPhi_R01_gen->Write();
	
  	hJetPt_R02->Write(); hJetEta_R02->Write(); hJetPhi_R02->Write();
        hJetPt_R02_gen->Write(); hJetEta_R02_gen->Write(); hJetPhi_R02_gen->Write();
	
	hJetPt_R03->Write(); hJetEta_R03->Write(); hJetPhi_R03->Write();
        hJetPt_R03_gen->Write(); hJetEta_R03_gen->Write(); hJetPhi_R03_gen->Write();

	hJetPt_R04->Write(); hJetEta_R04->Write(); hJetPhi_R04->Write();
        hJetPt_R04_gen->Write(); hJetEta_R04_gen->Write(); hJetPhi_R04_gen->Write();
	        
	hJetPtMatched_R01->Write(); hJetPtMatched_R02->Write();
        hJetPtMatched_R03->Write(); hJetPtMatched_R04->Write();
        hJetEtaMatched_R01->Write(); hJetEtaMatched_R02->Write();
        hJetEtaMatched_R03->Write(); hJetEtaMatched_R04->Write();

        hJetPtMatched_R01_gen->Write(); hJetPtMatched_R02_gen->Write();
        hJetPtMatched_R03_gen->Write(); hJetPtMatched_R04_gen->Write();
        hJetEtaMatched_R01_gen->Write(); hJetEtaMatched_R02_gen->Write();
        hJetEtaMatched_R03_gen->Write(); hJetEtaMatched_R04_gen->Write();

  //      ResponseR01->Write();ResponseR02->Write();ResponseR03->Write();
  //      ResponseR01pt->Write();ResponseR02pt->Write();ResponseR03pt->Write();
  //      RM_pro_R01->Write();RM_pro_R02->Write();RM_pro_R03->Write();
	sum->Write();

	// Plot fixes
        c1->cd();
        hJetPt_R01->SetTitle("Jet Pt spectra overview (Detector level)");
        c1->SaveAs("./EnergyFlow_plots/Jet_ptspectrum_detLevel_ppmc.png");

        c1a->cd();
        hJetEta_R01->SetTitle("Jet #eta distribution overview (Detector level)");
        c1a->SaveAs("./EnergyFlow_plots/Jet_etadist_detLevel_ppmc.png");

        c1b->cd();
        hJetPtMatched_R01->SetTitle("Matched jet p_{t} spectra overview (Detector level)");
        c1b->SaveAs("./EnergyFlow_plots/Matchedjet_ptspectrum_detLevel_ppmc.png");

        c1c->cd();
        hJetEtaMatched_R01->SetTitle("Matched jet #eta distribution overview (Detector level)");
        c1c->SaveAs("./EnergyFlow_plots/Matchedjet_etadist_detLevel_ppmc.png");

        c1_gen->cd();
	hJetPt_R01_gen->SetTitle("Jet Pt spectra overview (Generator level)");
        c1_gen->SaveAs("./EnergyFlow_plots/Jet_ptspectrum_genLevel_ppmc.png");

        c1a_gen->cd();
        hJetEta_R01_gen->SetTitle("Jet #eta distribution overview (Generator level)");
        c1a_gen->SaveAs("./EnergyFlow_plots/Jet_etadist_genLevel_ppmc.png");

        c1b_gen->cd();
        hJetPtMatched_R01_gen->SetTitle("Matched jet p_{t} spectra overview (Generator level)");
        c1b_gen->SaveAs("./EnergyFlow_plots/Matchedjet_ptspectrum_genLevel_ppmc.png");

        c1c_gen->cd();
        hJetEtaMatched_R01_gen->SetTitle("Matched jet #eta distribution overview (Generator level)");
        c1c_gen->SaveAs("./EnergyFlow_plots/Matchedjet_etadist_genLevel_ppmc.png");
/*
        c2->cd();
        pro_R01->SetTitle(TString::Format("#DeltaP_{t} projection overview [%d,%d](GeV/c) (Detector level)",Ptlow,Pthigh));
        c2->SaveAs(Form("./EnergyFlow_plots/Dpt_pro_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));

        c3->cd();
        pro_DR01->SetTitle(TString::Format("#DeltaR projection overview [%d,%d](GeV/c) (Detector level)",Ptlow,Pthigh));
        c3->SaveAs(Form("./EnergyFlow_plots/DR_pro_%d_%d_detLevel_ppmc.png",Ptlow,Pthigh));

        c2_gen->cd();
	pro_R01_gen->SetTitle(TString::Format("#DeltaP_{t} projection overview [%d,%d](GeV/c) (Generator level)",Ptlow,Pthigh));
        c2_gen->SaveAs(Form("./EnergyFlow_plots/Dpt_pro_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));
        
        c3_gen->cd();
	pro_DR01_gen->SetTitle(TString::Format("#DeltaR projection overview [%d,%d](GeV/c) (Generator level)",Ptlow,Pthigh));
	c3_gen->SaveAs(Form("./EnergyFlow_plots/DR_pro_%d_%d_genLevel_ppmc.png",Ptlow,Pthigh));
*/
        sum->Close();
        f1->Close();

        delete c1; delete c1a; delete c1b; delete c1c;
        delete c1_gen; delete c1a_gen; delete c1b_gen; delete c1c_gen;
        delete c2; delete c2_gen;delete c3; delete c3_gen;
        delete c4; delete c4_gen; delete c4a; delete c4a_gen;
        delete mult1; delete mult2; delete mult3;
        delete mult1_gen; delete mult2_gen; delete mult3_gen;
        delete legend1; delete legend1a; delete legend2; delete legend2a;
}
