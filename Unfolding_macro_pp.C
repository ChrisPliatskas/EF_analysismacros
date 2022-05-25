

void SetStyle(TH1* h1);

void Unfolding_macro_pp(TString DatafileName = "AnalysisResults.root",TString ResponsefileName = "ResponseMatrix_ppMC_ptmin0.root",Double_t Rjet = 0.1, Int_t Ptlow =0 , Int_t Pthigh = 100,Int_t Niter = 1){

//Response Matrix visualisation
TFile*ResponseFile = TFile::Open(ResponsefileName.Data());

TH2D* h2Dpt_Rebined_Meas = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_Meas_R%03d",int(Rjet*100))));

TH2D* h2Dpt_Rebined_True = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_True_R%03d",int(Rjet*100))));

Int_t nPtBins = h2Dpt_Rebined_Meas->GetNbinsX();
Double_t ptmin = h2Dpt_Rebined_Meas->GetXaxis()->GetXmin();
Double_t ptmax = h2Dpt_Rebined_Meas->GetXaxis()->GetXmax();

Int_t nDptBins = h2Dpt_Rebined_Meas->GetNbinsY();
Double_t Dptmin = h2Dpt_Rebined_Meas->GetYaxis()->GetXmin();
Double_t Dptmax = h2Dpt_Rebined_Meas->GetYaxis()->GetXmax();

 Int_t nPtBins_gen = h2Dpt_Rebined_True->GetNbinsX();
 Double_t ptmin_gen = h2Dpt_Rebined_True->GetXaxis()->GetXmin();
 Double_t ptmax_gen = h2Dpt_Rebined_True->GetXaxis()->GetXmax();
  
 Int_t nDptBins_gen = h2Dpt_Rebined_True->GetNbinsY();
 Double_t Dptmin_gen = h2Dpt_Rebined_True->GetYaxis()->GetXmin();
 Double_t Dptmax_gen = h2Dpt_Rebined_True->GetYaxis()->GetXmax();


Int_t Ptwidth = int(h2Dpt_Rebined_Meas->GetXaxis()->GetBinWidth(1));
//Int_t Ptlow_bin = h2Dpt_Rebined_Meas->GetXaxis()->FindBin(ptmin+ Ptlow);
//Int_t Pthigh_bin =h2Dpt_Rebined_Meas ->GetXaxis()->FindBin(ptmin+ Pthigh)-1;


Double_t Dptlow = Dptmin;
Double_t Dpthigh = Dptmax;

 
Double_t Dptlow_gen = Dptmin_gen;
Double_t Dpthigh_gen = Dptmax_gen;

Int_t Dptwidth = int(h2Dpt_Rebined_Meas->GetYaxis()->GetBinWidth(1));

          //Plotting the RM
          //Set drawing style
            gStyle->SetOptStat(0);
            gStyle->SetTextFont(42);
            gStyle->SetTitleFont(42);
            gStyle->SetTextSize(18);
            gStyle->SetOptTitle(1);
            gStyle->SetPadTickX(1);
            gStyle->SetPadTickY(1);
          gStyle->SetLabelOffset(.001);
          gStyle->SetTitleSize(0.05,"Y");
          gStyle->SetTitleSize(0.05,"X");
          gStyle->SetTitleSize(0.05);
          gStyle->SetTextSize(16);
          gStyle->SetHistLineWidth(2);
          gStyle->SetLegendTextSize(0.025);
          gStyle->SetTitleXOffset(.7);
          gStyle->SetTitleYOffset(.7);
          gStyle->SetTitleOffset(.7);


THnSparse* ResponseMatrix = static_cast<THnSparse*>(ResponseFile->Get(Form("ResponseMatrix_R%03d_0",int(Rjet*100))));
ResponseMatrix ->UseCurrentStyle();

Int_t Ptlow_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Ptlow);
Int_t Pthigh_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Pthigh+10)-1;
ResponseMatrix->GetAxis(0)->SetRange(Ptlow_bin_gen,Pthigh_bin_gen);
Int_t Ptlow_bin =ResponseMatrix->GetAxis(0)->FindBin(Ptlow);
Int_t Pthigh_bin =ResponseMatrix->GetAxis(0)->FindBin(Pthigh)-1;
ResponseMatrix->GetAxis(1)->SetRange(Ptlow_bin,Pthigh_bin);
TH2D *Pt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(0,1,"E"));
//Pt_RM->SetMinimum(1e-8);Pt_RM->SetMaximum(1e3);
Pt_RM->SetName(Form("Pt_ResponseMatrix_R%03d_0",int(Rjet*100)));
Pt_RM->SetTitle(Form("Response Matrix for P_{t} of R_{jet}=%.2f;P_{t} (Detector level);P_{t}(Generator level)",Rjet));

Int_t Dptlow_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dptlow_gen);
Int_t Dpthigh_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh_gen)-1;
ResponseMatrix->GetAxis(2)->SetRange(Dptlow_bin_gen,Dpthigh_bin_gen);
Int_t Dptlow_bin = ResponseMatrix->GetAxis(2)->FindBin(Dptlow);
Int_t Dpthigh_bin = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh)-1;
ResponseMatrix->GetAxis(3)->SetRange(Dptlow_bin,Dpthigh_bin);
TH2D *DPt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(2,3,"E"));
//DPt_RM->SetMinimum(1e-8);DPt_RM->SetMaximum(1e3);
DPt_RM->SetName(Form("DPt_ResponseMatrix_R%03d_0",int(Rjet*100)));
DPt_RM->SetTitle(Form("Response Matrix for #DeltaP_{t} of R_{jet}=%.2f- P_{t} bin [%d,%d];#DeltaP_{t} (Detector level);#DeltaP_{t}(Generator level)",Rjet,Ptlow,Pthigh));

        //Plotting the response matrix for jet Pt
TCanvas* c_pt_response = new TCanvas("c_Pt_response","c_Pt_response",1200,1200);
c_pt_response->SetLogz(1);
Pt_RM->Draw("colz");
c_pt_response->Update();
TPaletteAxis* pal = (TPaletteAxis*)Pt_RM->GetListOfFunctions()->FindObject("palette");
pal->SetX2(Pthigh+4);
c_pt_response->Update();
c_pt_response->SaveAs(Form("./Unfolding_plots/Iterations%d/ResponseMatrix/ptMIN%d_DptMIN%d/RM_pt_R%03d_pt_%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));
        //Plotting the response matrix for DeltaPt
TCanvas* c_Dpt_response = new TCanvas("c_DPt_response","c_DPt_response",1200,1200);
c_Dpt_response->SetLogz(1);
DPt_RM->Draw("colz");
c_Dpt_response->Update();
TPaletteAxis* pal2 = (TPaletteAxis*)DPt_RM->GetListOfFunctions()->FindObject("palette");
pal2->SetX2(Dpthigh+3);
DPt_RM->Draw("colz");
c_Dpt_response->SaveAs(Form("./Unfolding_plots/Iterations%d/ResponseMatrix/ptMIN%d_DptMIN%d/RM_Dpt_R%03d_pt_%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

//Load & Rebin data distribution
TFile*Datafile = TFile::Open(DatafileName.Data());
AliEmcalList* ali;
Datafile->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_smallRstep_histos",ali);

TH2D*hDpt_data = static_cast<TH2D*>(ali->FindObject(Form("hJetPtDeltaPt_R%03d_0",int(Rjet*100))));

TH2D *Dpt_Rebinned_Data = new TH2D(Form("Dpt_Rebinned_DataR%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (ALICE data -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);

        for(Int_t ix=1;ix<=Dpt_Rebinned_Data->GetNbinsX();ix++){
        Double_t xlow = Dpt_Rebinned_Data->GetXaxis()->GetBinLowEdge(ix);
        Double_t xup = Dpt_Rebinned_Data->GetXaxis()->GetBinUpEdge(ix);
        Int_t jxlow = hDpt_data->GetXaxis()->FindBin(xlow+0.000001);
        Int_t jxup = hDpt_data->GetXaxis()->FindBin(xup-0.000001);
        for(Int_t iy = 1; iy<=Dpt_Rebinned_Data->GetNbinsY(); iy++) {
          Double_t ylow = Dpt_Rebinned_Data->GetYaxis()->GetBinLowEdge(iy);
          Double_t yup =Dpt_Rebinned_Data->GetYaxis()->GetBinUpEdge(iy);
          Int_t jylow = hDpt_data->GetYaxis()->FindBin(ylow+0.000001);
          Int_t jyup = hDpt_data->GetYaxis()->FindBin(yup-0.000001);
    
          Double_t err = 0.; 
          Double_t con = hDpt_data->IntegralAndError(jxlow,jxup,jylow,jyup,err);
          Dpt_Rebinned_Data->SetBinContent(ix,iy,con);
          Dpt_Rebinned_Data->SetBinError(ix,iy,err);
           } //End of ybin loop
           } //End of xbin loop

//Unfold rebinned data distro
RooUnfoldResponse* resp = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%03d",int(Rjet*100))));
TString Unfoldname =Form("Bayesian_Unfolding_R%d_ptmin%d",int(Rjet*100),int(ptmin));
RooUnfoldBayes Unfolding_bayes(resp,Dpt_Rebinned_Data,Niter,0,Unfoldname,Unfoldname);
TH2D* Unfolded_Dpt_data = (TH2D*)Unfolding_bayes.Hreco();

//Refold Unfolded data distro
TH2D* Refolded_Dpt_data = (TH2D*) resp->ApplyToTruth(Unfolded_Dpt_data,Form("Refolded_Dpt_data_R%03d",int(Rjet*100)));

Int_t Pro_bin_ptlow =Dpt_Rebinned_Data->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh =Dpt_Rebinned_Data->GetXaxis()->FindBin(Pthigh)-1;


//Projections

        //Initial data distro
        TH1D*pro_data = Dpt_Rebinned_Data->ProjectionY(Form("pro_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_data->Scale(1/pro_data->Integral());

        //Det level MC
        TH1D*pro_mc_det = h2Dpt_Rebined_Meas->ProjectionY(Form("pro_mc_det_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_mc_det->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC DEtector level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_det->Scale(1/pro_mc_det->Integral());

        //Gen level MC
        TH1D*pro_mc_gen = h2Dpt_Rebined_True->ProjectionY(Form("pro_mc_gen_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_mc_gen->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC Generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_gen->Scale(1/pro_mc_gen->Integral());

        //Unfolded data
        TH1D*pro_unfolded_data = Unfolded_Dpt_data->ProjectionY(Form("pro_unfolded_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_unfolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_unfolded_data->Scale(1/pro_unfolded_data->Integral());

        //Refolded data
        TH1D*pro_refolded_data = Refolded_Dpt_data->ProjectionY(Form("pro_refolded_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_refolded_data->Scale(1/pro_refolded_data->Integral());

//Ratios

        //MC Truth over detector level
        TH1D*Ratio_MCgenoverdet =(TH1D*)pro_mc_gen->Clone();
        Ratio_MCgenoverdet->Reset();
        for (int i_bin=0;i_bin<pro_mc_det->GetNbinsX();i_bin++){
                Ratio_MCgenoverdet->SetBinContent(i_bin,pro_mc_det->GetBinContent(i_bin)); 
                Ratio_MCgenoverdet->SetBinError(i_bin,pro_mc_det->GetBinError(i_bin));}
  
        Ratio_MCgenoverdet->Divide(pro_mc_gen,Ratio_MCgenoverdet);
        Ratio_MCgenoverdet->SetTitle(Form("Ratio of Truth over Detector level #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Truth}{Detector}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
        Ratio_MCgenoverdet->SetName(Form("Ratio_GenDet_R%03d",int(Rjet*100)));
  
        //Unfolded data over data
          TH1D*Ratio_UnfoverData =(TH1D*)pro_unfolded_data->Clone();
          Ratio_UnfoverData->Reset();
          for (int i_bin=0;i_bin<pro_data->GetNbinsX();i_bin++){
                  Ratio_UnfoverData->SetBinContent(i_bin,pro_data->GetBinContent(i_bin)); 
                  Ratio_UnfoverData->SetBinError(i_bin,pro_data->GetBinError(i_bin));}
    
          Ratio_UnfoverData->Divide(pro_unfolded_data,Ratio_UnfoverData);
          Ratio_UnfoverData->SetTitle(Form("Ratio of Unfolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_UnfoverData->SetName(Form("Ratio_UnfData_R%03d",int(Rjet*100)));

        //Refolded over data
          TH1D*Ratio_RefoverData =(TH1D*)pro_refolded_data->Clone();
          Ratio_RefoverData->Reset();
          Ratio_RefoverData->Divide(pro_refolded_data,pro_data);
          Ratio_RefoverData->SetTitle(Form("Ratio of Refolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Refolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_RefoverData->SetName(Form("Ratio_RefData_R%03d",int(Rjet*100)));

        //MC Truth over Unfolded data
        TH1D*Ratio_MCgenoverUnf =(TH1D*)pro_mc_gen->Clone();
        Ratio_MCgenoverUnf->Reset();
        Ratio_MCgenoverUnf->Divide(pro_mc_gen,pro_unfolded_data);
        Ratio_MCgenoverUnf->SetTitle(Form("Ratio of Truth level MC over Unfolded data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{MC Truth level}{Unfolded Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
        Ratio_MCgenoverUnf->SetName(Form("Ratio_MCgenUnfData_R%03d",int(Rjet*100)));

        //MC Detector level over Data
        TH1D*Ratio_MCdetoverData =(TH1D*)pro_mc_det->Clone();
        Ratio_MCdetoverData->Reset();
        Ratio_MCdetoverData->Divide(pro_mc_det,pro_data);
        Ratio_MCdetoverData->SetTitle(Form("Ratio of Detector level MC over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{MC Detector level}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
        Ratio_MCdetoverData->SetName(Form("Ratio_MCdetData_R%03d",int(Rjet*100)));


//Plotting
    
        //MC detector vs particle level
        TCanvas* c_mc = new TCanvas("c_mc","c_mc",1200,1200);        
        c_mc->DrawFrame(Dptmin,1e-8,Dptmax,10,Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Detector vs Generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        c_mc->SetLogy(1);
        c_mc->SetGridy(1);
        SetStyle(pro_mc_det); SetStyle(pro_mc_gen);
        pro_mc_det->SetLineColor(kBlue);pro_mc_det->SetMarkerColor(kBlue);
        pro_mc_gen->SetLineColor(2);pro_mc_gen->SetMarkerColor(2);
        pro_mc_det->Draw("same");
        pro_mc_gen->Draw("same");

        TLatex latex;
        latex.SetTextAlign(13);
        latex.SetTextSize(0.03);
        latex.DrawLatex(5,3,Form("PYTHIA R=%.2f",Rjet));
        latex.DrawLatex(5,1,Form("Jet P_{t} [%d,%d] (GeV/c)",Ptlow,Pthigh));

        TLegend* leg1 = new TLegend(.7,.75,.9,.9);
        leg1->AddEntry(pro_mc_det,"Detector","p");
        leg1->AddEntry(pro_mc_gen,"Generator","p");
        leg1->Draw("same");
        c_mc->SaveAs(Form("./Unfolding_plots/Iterations%d/McdetvsMcgen/ptMIN%d_DptMIN%d/Dpt_pro_MCdet_gen_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));


        //MC detector vs ALICE data
        TCanvas* c_Det = new TCanvas("c_Det","c_Det",1200,1200);    
          c_Det->DrawFrame(Dptmin,1e-8,Dptmax,10,Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d]GeV/c (ALICE data vs MC detector level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
          c_Det->SetLogy(1);
          c_Det->SetGridy(1);
          SetStyle(pro_mc_det); SetStyle(pro_data);
          pro_mc_det->SetLineColor(kBlue);pro_mc_det->SetMarkerColor(kBlue);
          pro_data->SetLineColor(2);pro_data->SetMarkerColor(2);
          pro_mc_det->Draw("same");
          pro_data->Draw("same");
  
          TLatex latex2;
          latex2.SetTextAlign(13);
          latex2.SetTextSize(0.03);
          latex2.DrawLatex(5,2,Form("R=%.2f",Rjet));
          latex2.DrawLatex(5,5,"PYTHIA vs ALICE");
          latex2.DrawLatex(5,.9,Form("Jet P_{t} [%d,%d] (GeV/c)",Ptlow,Pthigh));
          
          TLegend* leg2 = new TLegend(.7,.75,.9,.9);
          leg2->AddEntry(pro_mc_det,"Detector level","p");
          leg2->AddEntry(pro_data,"Data","p");
          leg2->Draw("same");
         c_Det->SaveAs(Form("./Unfolding_plots/Iterations%d/DatavsMCdet/ptMIN%d_DptMIN%d/Dpt_pro_data_MCdet_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

        //MC particle vs Unfolded data
          TCanvas* c_Unf = new TCanvas("c_Unf","c_Unf",1200,1200);
          c_Unf->DrawFrame(Dptmin,1e-8,Dptmax,10,Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d]GeV/c (Unfolded ALICE data vs MC generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
            c_Unf->SetLogy(1);
            c_Unf->SetGridy(1);
            SetStyle(pro_unfolded_data); SetStyle(pro_mc_gen);
            pro_mc_gen->SetLineColor(kBlue);pro_mc_gen->SetMarkerColor(kBlue);
            pro_unfolded_data->SetLineColor(2);pro_unfolded_data->SetMarkerColor(2);
            pro_mc_gen->Draw("same");
            pro_unfolded_data->Draw("same");
  
            TLatex latex3;
            latex3.SetTextAlign(13);
            latex3.SetTextSize(0.03);
            latex3.DrawLatex(5,2,Form("R=%.2f",Rjet));
            latex3.DrawLatex(5,5,"PYTHIA vs ALICE");
            latex3.DrawLatex(5,.9,Form("Jet P_{t} [%d,%d] (GeV/c)",Ptlow,Pthigh));

            TLegend* leg3 = new TLegend(.7,.75,.9,.9);
            leg3->AddEntry(pro_mc_gen,"Generator level","p");
            leg3->AddEntry(pro_unfolded_data,"Unfolded data","p");
            leg3->Draw("same");
            c_Unf->SaveAs(Form("./Unfolding_plots/Iterations%d/UnfDatavsMCgen/ptMIN%d_DptMIN%d/Dpt_pro_Unfdata_MCgen_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

        //Unfolded vs ALICE data
        TCanvas* c_Unf2 = new TCanvas("c_Unf2","c_Unf2",1200,1200);
            c_Unf2->DrawFrame(Dptmin,1e-8,Dptmax,10,Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d]GeV/c (ALICE data vs Unfolded ALICE data );#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
              c_Unf2->SetLogy(1);
              c_Unf2->SetGridy(1);
              SetStyle(pro_unfolded_data); SetStyle(pro_data);
              pro_data->SetLineColor(kBlue);pro_data->SetMarkerColor(kBlue);
              pro_unfolded_data->SetLineColor(2);pro_unfolded_data->SetMarkerColor(2);
              pro_data->Draw("same");
              pro_unfolded_data->Draw("same");
    
              TLatex latex4;
              latex4.SetTextAlign(13);
              latex4.SetTextSize(0.03);
              latex4.DrawLatex(5,3,Form("ALICE R=%.2f",Rjet));
              latex4.DrawLatex(5,1,Form("Jet P_{t} [%d,%d] (GeV/c)",Ptlow,Pthigh));

              TLegend* leg3a = new TLegend(.7,.75,.9,.9);
              leg3a->AddEntry(pro_data,"Data","p");
              leg3a->AddEntry(pro_unfolded_data,"Unfolded data","p");
              leg3a->Draw("same");
              c_Unf2->SaveAs(Form("./Unfolding_plots/Iterations%d/UnfDatavsData/ptMIN%d_DptMIN%d/Dpt_pro_Unfdata_data_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));


        //Refolded vs ALICE data
            TCanvas* c_Ref = new TCanvas("c_Ref","c_Ref",1200,1200);
              c_Ref->DrawFrame(Dptmin,1e-8,Dptmax,10,Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d]GeV/c (Refolded ALICE data vs ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
              c_Ref->SetLogy(1);
              c_Ref->SetGridy(1);
             
              SetStyle(pro_refolded_data); SetStyle(pro_data);
              pro_refolded_data->SetLineColor(kBlue);pro_refolded_data->SetMarkerColor(kBlue);
              pro_data->SetLineColor(kRed);pro_data->SetMarkerColor(kRed);
              pro_data->Draw("same");
              pro_refolded_data->Draw("same");
  
                TLatex latex5;
                latex5.SetTextAlign(13);
                latex5.SetTextSize(0.03);
                latex5.DrawLatex(5,3,Form("ALICE R=%.2f",Rjet));
                latex5.DrawLatex(5,1,Form("Jet P_{t} [%d,%d] (GeV/c)",Ptlow,Pthigh));
              TLegend* leg4 = new TLegend(.7,.75,.9,.9);
              leg4->AddEntry(pro_data,"Data","p");
              leg4->AddEntry(pro_refolded_data,"Refolded data","p");
              leg4->Draw("same");    
              c_Ref->SaveAs(Form("./Unfolding_plots/Iterations%d/DatavsRefoldedData/ptMIN%d_DptMIN%d/Dpt_pro_Refdata_data_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));
        
          //Plotting Ratios
                //MC gen vs MC Det
        TCanvas* c_RatioMCgenDet = new TCanvas("c_RatioMCgenDet","c_RatioMCgenDet",1400,1000);
        c_RatioMCgenDet->SetGridy(1);
        c_RatioMCgenDet->SetGridx(1);
        Ratio_MCgenoverdet->Draw();
        c_RatioMCgenDet->SaveAs(Form("./Unfolding_plots/Iterations%d/McdetvsMcgen/ptMIN%d_DptMIN%d/Dpt_Ratio_MCgenDet_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

                //Unfolded data vs Data
         TCanvas* c_RatioUnfData = new TCanvas("c_RatioUnfData","c_RatioUnfData",1400,1000);
         c_RatioUnfData->SetGridy(1);
         c_RatioUnfData->SetGridx(1);
         Ratio_UnfoverData->Draw();
         c_RatioUnfData->SaveAs(Form("./Unfolding_plots/Iterations%d/UnfDatavsData/ptMIN%d_DptMIN%d/Dpt_Ratio_UnfData_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));
                
                //Refolded data vs Data
         TCanvas* c_RatioRefData = new TCanvas("c_RatioRefData","c_RatioRefData",1400,1000);
        c_RatioRefData->SetGridy(1);
        c_RatioRefData->SetGridx(1);
        Ratio_RefoverData->Draw();
        c_RatioRefData->SaveAs(Form("./Unfolding_plots/Iterations%d/DatavsRefoldedData/ptMIN%d_DptMIN%d/Dpt_Ratio_RefData_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

               //MC Truth vs Unfolded data
        TCanvas* c_RatioMCgenUnf = new TCanvas("c_RatioMCgenUnf","c_RatioMCgenUnf",1400,1000);
        c_RatioMCgenUnf->SetGridy(1);
        c_RatioMCgenUnf->SetGridx(1);
        Ratio_MCgenoverUnf->Draw();
        c_RatioMCgenUnf->SaveAs(Form("./Unfolding_plots/Iterations%d/UnfDatavsMCgen/ptMIN%d_DptMIN%d/Dpt_Ratio_MCgenUnfData_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

                //MC Detector vs Data
        TCanvas* c_RatioMCdetData = new TCanvas("c_RatioMCdetData","c_RatioMCdetData",1400,1000);
          c_RatioMCdetData->SetGridy(1);
          c_RatioMCdetData->SetGridx(1);
        Ratio_MCdetoverData->Draw();
        c_RatioMCdetData->SaveAs(Form("./Unfolding_plots/Iterations%d/DatavsMCdet/ptMIN%d_DptMIN%d/Dpt_Ratio_MCdetData_R%03d_pt%d_%d_ptMIN%d_Dptmin%d_smallR.png",Niter,int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

        //Cleaning up

        delete c_pt_response; delete c_Dpt_response;
        delete c_Det; delete leg2;
        delete c_mc; delete leg1;
        delete c_Unf2; delete leg3a;
        delete c_Unf; delete leg3;
        delete c_Ref; delete leg4;
        delete c_RatioMCgenDet;
        delete c_RatioUnfData;
        delete c_RatioRefData;
        delete c_RatioMCgenUnf;
        delete c_RatioMCdetData;

        //Saving the output
        TString Outputname = Form("UnfoldedResults_pp_smallR_pt_%d_%d_ptmin%d_Dptmin%d_Iter%d.root",Ptlow,Pthigh,int(ptmin),int(Dptmin),Niter);
        TFile *fout = new TFile(Outputname.Data(),"UPDATE");
        
        Dpt_Rebinned_Data->Write(Dpt_Rebinned_Data->GetName(),TObject::kOverwrite);
        Pt_RM->Write(Pt_RM->GetName(),TObject::kOverwrite);
        DPt_RM->Write(DPt_RM->GetName(),TObject::kOverwrite);
        ResponseMatrix->Write(ResponseMatrix->GetName(),TObject::kOverwrite);
        Unfolded_Dpt_data->Write(Unfolded_Dpt_data->GetName(),TObject::kOverwrite);
        Refolded_Dpt_data->Write(Refolded_Dpt_data->GetName(),TObject::kOverwrite);
        pro_data->Write(pro_data->GetName(),TObject::kOverwrite);
        pro_mc_det->Write(pro_mc_det->GetName(),TObject::kOverwrite);
        pro_mc_gen->Write(pro_mc_gen->GetName(),TObject::kOverwrite);
        pro_unfolded_data->Write(pro_unfolded_data->GetName(),TObject::kOverwrite);
        pro_refolded_data->Write(pro_refolded_data->GetName(),TObject::kOverwrite);
        Ratio_MCgenoverdet->Write(Ratio_MCgenoverdet->GetName(),TObject::kOverwrite);
        Ratio_UnfoverData->Write(Ratio_UnfoverData->GetName(),TObject::kOverwrite);
        Ratio_RefoverData->Write(Ratio_RefoverData->GetName(),TObject::kOverwrite);
        Ratio_MCgenoverUnf->Write(Ratio_MCgenoverUnf->GetName(),TObject::kOverwrite);
        Ratio_MCdetoverData->Write(Ratio_MCdetoverData->GetName(),TObject::kOverwrite);
        Datafile->Close();
        ResponseFile->Close();
        fout->Close();
}

void SetStyle(TH1* h1){
        gStyle->SetOptStat(0);
        gStyle->SetTextFont(42);
        gStyle->SetTitleFont(42);
        gStyle->SetOptTitle(1);
        gStyle->SetPadTickX(1);
        gStyle->SetPadTickY(1);
        h1->SetMarkerStyle(33);
        h1->SetMarkerSize(2);
        h1->SetLineWidth(2);
        }
