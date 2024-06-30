double payoff_cash_or_nothing_call(const double& price, const double& X){
    if (price>=X) return 1;
    return 0;
};

double payoff_asset_or_nothing_call(const double& price, const double& X){
    if (price>=X) return price;
    return 0;
};
