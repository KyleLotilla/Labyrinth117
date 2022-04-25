// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialMenuUI.h"

void UTutorialMenuUI::NavigatePage(int index_)
{
	if (index_ >= 0 && index_ < this->tutorialPages.Num())
	{
		UUserWidget* page = CreateWidget<UUserWidget>(this, this->tutorialPages[index_]);
		if (page)
		{
			this->index = index_;
			box->ClearChildren();
			UHorizontalBoxSlot* boxSlot = box->AddChildToHorizontalBox(page);
			FSlateChildSize sizeRule;
			sizeRule.SizeRule = ESlateSizeRule::Fill;
			boxSlot->SetSize(sizeRule);

			if (this->index == 0)
			{
				this->backButton->SetIsEnabled(false);
			}
			else
			{
				this->backButton->SetIsEnabled(true);
			}

			if (this->index == this->tutorialPages.Num() - 1)
			{
				this->forwardButton->SetIsEnabled(false);
				this->okButton->SetIsEnabled(true);
			}
			else
			{
				this->forwardButton->SetIsEnabled(true);
				this->okButton->SetIsEnabled(false);
			}
		}
	}
}
