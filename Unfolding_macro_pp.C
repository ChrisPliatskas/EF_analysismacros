

void SetStyle(TH1* h1);

void Unfolding_macro_pp(TString DatafileName = "AnalysisResults.root",TString ResponsefileName = "ResponseMatrix_ppMC_ptmin0.root",Double_t Rjet = 0.1, Int_t Ptlow =0 , Int_t Pthigh = 100,Int_t Niter = 1){

//Response Matrix visualisation
TFile*ResponseFile = TFile::Open(ResponsefileName.Data());

TH2D* h2Dpt_Rebined_Meas = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_Meas_R%d",int(Rjet*100))));

TH2D* h2Dpt_Rebined_True = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_True_R%d",int(Rjet*100))));

Int_t nPtBins = h2Dpt_Rebined_Meas->GetNbinsX();
Double_t ptmin = h2Dpt_Rebined_Meas->GetXaxis()->GetXmin();
Double_t ptmax = h2Dpt_Rebined_Meas->GetXaxis()->GetXmax();

Int_t nDptBins = h2Dpt_Rebined_Meas->GetNbinsY();
Double_t Dptmin = h2Dpt_Rebined_Meas->GetYaxis()->GetXmin();
Double_t Dptmax = h2Dpt_Rebined_Meas->GetYaxis()->GetXmax();

Int_t Ptwidth = int((ptmax-ptmin)/nPtBins);
//Int_t Ptlow_bin = h2Dpt_Rebined_Meas->GetXaxis()->FindBin(ptmin+ Ptlow);
//Int_t Pthigh_bin =h2Dpt_Rebined_Meas ->GetXaxis()->FindBin(ptmin+ Pthigh)-1;


Double_t Dptlow = Dptmin;
Double_t Dpthigh = Dptmax;

Int_t Dptwidth = int((Dptmax-Dptmin)/nDptBins);
//Int_t Dptlow_bin = h2Dpt_Rebined_Meas->GetYaxis()->FindBin(Dptlow);
//Int_t Dpthigh_bin =h2Dpt_Rebined_Meas ->GetYaxis()->FindBin(Dpthigh)-1;


THnSparse* ResponseMatrix = static_cast<THnSparse*>(ResponseFile->Get(Form("ResponseMatrix_R%d_0",int(Rjet*100))));

Int_t Ptlow_bin =ResponseMatrix->GetAxis(0)->FindBin(ptmin+ Ptlow);
Int_t Pthigh_bin =ResponseMatrix->GetAxis(0)->FindBin(ptmin+ Pthigh)-1;
ResponseMatrix->GetAxis(0)->SetRange(Ptlow_bin,Pthigh_bin);
ResponseMatrix->GetAxis(1)->SetRange(Ptlow_bin,Pthigh_bin);
TH2D *Pt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(0,1,"E"));
Pt_RM->SetName(Form("Pt_ResponseMatrix_R%d_0",int(Rjet*100)));
Pt_RM->SetTitle(Form("Response Matrix for P_{t} of R_{jet}=%.2f;P_{t} (Detector level);P_{t}(Generator level)",Rjet));

Int_t Dptlow_bin = ResponseMatrix->GetAxis(2)->FindBin(Dptlow);
Int_t Dpthigh_bin = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh)-1;
ResponseMatrix->GetAxis(2)->SetRange(Dptlow_bin,Dpthigh_bin);
ResponseMatrix->GetAxis(3)->SetRange(Dptlow_bin,Dpthigh_bin);
TH2D *DPt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(2,3,"E"));
DPt_RM->SetName(Form("DPt_ResponseMatrix_R%d_0",int(Rjet*100)));
DPt_RM->SetTitle(Form("Response Matrix for #DeltaP_{t} of R_{jet}=%.2f- P_{t} bin [%d,%d];#DeltaP_{t} (Detector level);#DeltaP_{t}(Generator level)",Rjet,Ptlow,Pthigh));

        //Plotting the RM
        //Set drawing style
          gStyle->SetOptStat(0);
          gStyle->SetTextFont(42);
          gStyle->SetTitleFont(42);
          gStyle->SetTextSize(18);
          gStyle->SetOptTitle(1);
          gStyle->SetPadTickX(1);
          gStyle->SetPadTickY(1);
        gStyle->SetTitleSize(0.05,"Y");
        gStyle->SetTitleSize(0.05,"X");
        gStyle->SetTitleSize(0.05);
        gStyle->SetTextSize(16);

        //Plotting the response matrix for jet Pt
TCanvas* c_pt_response = new TCanvas("c_Pt_response","c_Pt_response",1200,1200);
c_pt_response->SetLogz(1);
Pt_RM->Draw("colz");
c_pt_response->SaveAs(Form("./Unfolding_plots/ResponseMatrix/ptMIN%d_DptMIN%d/RM_pt_R%d_pt_%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));
        //Plotting the response matrix for DeltaPt
TCanvas* c_Dpt_response = new TCanvas("c_DPt_response","c_DPt_response",1200,1200);
c_Dpt_response->SetLogz(1);
DPt_RM->Draw("colz");
c_Dpt_response->SaveAs(Form("./Unfolding_plots/ResponseMatrix/ptMIN%d_DptMIN%d/RM_Dpt_R%d_pt_%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

//Load & Rebin data distribution
TFile*Datafile = TFile::Open(DatafileName.Data());
AliEmcalList* ali;
Datafile->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_run17_histos",ali);

TH2D*hDpt_data = static_cast<TH2D*>(ali->FindObject(Form("hJetPtDeltaPt_R%d_0",int(Rjet*100))));

TH2D *Dpt_Rebinned_Data = new TH2D(Form("Dpt_Rebinned_DataR%d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (ALICE data -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);

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
RooUnfoldResponse* resp = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%d",int(Rjet*100))));
TString Unfoldname =Form("Bayesian_Unfolding_R%d_ptmin%d",int(Rjet*100),int(ptmin));
RooUnfoldBayes Unfolding_bayes(resp,Dpt_Rebinned_Data,Niter,0,Unfoldname,Unfoldname);
TH2D* Unfolded_Dpt_data = (TH2D*)Unfolding_bayes.Hreco();

//Refold Unfolded data distro
TH2D* Refolded_Dpt_data = (TH2D*) resp->ApplyToTruth(Unfolded_Dpt_data,Form("Refolded_Dpt_data_R%d",int(Rjet*100)));

//Projections

        //Initial data distro
        TH1D*pro_data = Dpt_Rebinned_Data->ProjectionY(Form("pro_data_R%d",int(Rjet*100)),Ptlow_bin,Pthigh_bin);
        pro_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_data->Scale(1/pro_data->Integral());

        //Det level MC
        TH1D*pro_mc_det = h2Dpt_Rebined_Meas->ProjectionY(Form("pro_mc_det_R%d",int(Rjet*100)),Ptlow_bin,Pthigh_bin);
        pro_mc_det->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC DEtector level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_det->Scale(1/pro_mc_det->Integral());

        //Gen level MC
        TH1D*pro_mc_gen = h2Dpt_Rebined_True->ProjectionY(Form("pro_mc_gen_R%d",int(Rjet*100)),Ptlow_bin,Pthigh_bin);
        pro_mc_gen->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC Generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_gen->Scale(1/pro_mc_gen->Integral());

        //Unfolded data
        TH1D*pro_unfolded_data = Unfolded_Dpt_data->ProjectionY(Form("pro_unfolded_data_R%d",int(Rjet*100)),Ptlow_bin,Pthigh_bin);
        pro_unfolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_unfolded_data->Scale(1/pro_unfolded_data->Integral());

        //Refolded data
        TH1D*pro_refolded_data = Refolded_Dpt_data->ProjectionY(Form("pro_refolded_data_R%d",int(Rjet*100)),Ptlow_bin,Pthigh_bin);
        pro_refolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_refolded_data->Scale(1/pro_refolded_data->Integral());

//Ratios

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

        TLegend* leg1 = new TLegend(.6,.6,.9,.9);
        leg1->AddEntry(pro_mc_det,"Detector level","p");
        leg1->AddEntry(pro_mc_gen,"Generator level","p");
        leg1->Draw("same");
        c_mc->SaveAs(Form("./Unfolding_plots/McdetvsMCgen/ptMIN%d_DptMIN%d/Dpt_pro_MCdet_gen_R%d_pt%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));


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
  
          TLegend* leg2 = new TLegend(.6,.6,.9,.9);
          leg2->AddEntry(pro_mc_det,"Detector level","p");
          leg2->AddEntry(pro_data,"Data","p");
          leg2->Draw("same");
         c_Det->SaveAs(Form("./Unfolding_plots/DatavsMCdet/ptMIN%d_DptMIN%d/Dpt_pro_data_MCdet_R%d_pt%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

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
  
            TLegend* leg3 = new TLegend(.6,.6,.9,.9);
            leg3->AddEntry(pro_mc_gen,"Generator level","p");
            leg3->AddEntry(pro_unfolded_data,"Unfolded data","p");
            leg3->Draw("same");
            c_Unf->SaveAs(Form("./Unfolding_plots/UnfDatavsMCgen/ptMIN%d_DptMIN%d/Dpt_pro_Unfdata_MCgen_R%d_pt%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));

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
    
              TLegend* leg3a = new TLegend(.6,.6,.9,.9);
              leg3a->AddEntry(pro_data,"Data","p");
              leg3a->AddEntry(pro_unfolded_data,"Unfolded data","p");
              leg3a->Draw("same");
              c_Unf2->SaveAs(Form("./Unfolding_plots/UnfDatavsData/ptMIN%d_DptMIN%d/Dpt_pro_Unfdata_data_R%d_pt%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));


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
  
              TLegend* leg4 = new TLegend(.6,.6,.9,.9);
              leg4->AddEntry(pro_data,"Data","p");
              leg4->AddEntry(pro_refolded_data,"Refolded data","p");
              leg4->Draw("same");    
              c_Ref->SaveAs(Form("./Unfolding_plots/DatavsRefoldedData/ptMIN%d_DptMIN%d/Dpt_pro_Refdata_data_R%d_pt%d_%d_ptMIN%d_Dptmin%d.png",int(ptmin),int(Dptmin),int(Rjet*100),Ptlow,Pthigh,int(ptmin),int(Dptmin)));
        //Cleaning up

        delete c_pt_response; delete c_Dpt_response;
        delete c_Det; delete leg2;
        delete c_mc; delete leg1;
        delete c_Unf2; delete leg3a;
        delete c_Unf; delete leg3;
        delete c_Ref; delete leg4;

        //Saving the output
        TString Outputname = Form("UnfoldedResults_pp_pt_%d_%d_ptmin%d_Dptmin%d.root",Ptlow,Pthigh,int(ptmin),int(Dptmin));
        TFile *fout = new TFile(Outputname.Data(),"UPDATE");
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
