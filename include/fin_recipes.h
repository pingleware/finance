// file: fin_recipes.h
// author: Bernt Arne Oedegaard
//   defines all routines in the financial numerical recipes "book"

#ifndef _FIN_RECIPES_H_
#define _FIN_RECIPES_H_

#include <vector>
using namespace std;

///////// present value ////////////////////////////////////
// discrete coumpounding
/////////////////////////////////
// discrete, annual compounding

double cash_flow_pv_discrete ( const vector<double>& cflow_times, const vector<double>& cflow_amounts,
			       const double& r);
double cash_flow_irr_discrete(const vector<double>& cflow_times, const vector<double>& cflow_amounts);
bool cash_flow_unique_irr(const vector<double>& cflow_times, const vector<double>& cflow_amounts);
double bonds_price_discrete(const vector<double>& cashflow_times, const vector<double>& cashflows,
			    const double& r);  
double bonds_yield_to_maturity_discrete(const vector<double>& times,
					const vector<double>& amounts,
					const double& bondprice);
double bonds_duration_discrete(const vector<double>& times, 
			       const vector<double>& cashflows,
			       const double& r);
double bonds_duration_macaulay_discrete(const vector<double>& cashflow_times, 
					const vector<double>& cashflows,
					const double& bond_price);
double bonds_duration_modified_discrete (const vector<double>& times,
					 const vector<double>& amounts,
					 const double& bond_price);
double bonds_convexity_discrete(const vector<double>& cflow_times, 
				const vector<double>& cflow_amounts,
				const double& r);
/////////////////////////////////
// continous compounding. 
double cash_flow_pv(const vector<double>& cflow_times,const vector<double>& cflow_amounts,const double& r);
double cash_flow_irr(const vector<double>& cflow_times, const vector<double>& cflow_amounts);
double bonds_price(const vector<double>& cashflow_times, const vector<double>& cashflows, const double& r);
double bonds_price(const vector<double>& coupon_times, const vector<double>& coupon_amounts,
		   const vector<double>& principal_times, const vector<double>& principal_amounts, 
		   const double& r);
double bonds_duration(const vector<double>& cashflow_times, const vector<double>& cashflows,
		      const double& r);
double bonds_yield_to_maturity(const vector<double>& cashflow_times,const vector<double>& cashflow_amounts,
			       const double& bondprice);
double bonds_duration_macaulay(const vector<double>& cashflow_times, const vector<double>& cashflows,
			       const double& bond_price);
double bonds_convexity(const vector<double>& cashflow_times, const vector<double>& cashflow_amounts,
		       const double& y );

/// term structure basics 

double term_structure_yield_from_discount_factor(const double& dfact, const double& t); 
double term_structure_discount_factor_from_yield(const double& r, const double& t);
double term_structure_forward_rate_from_discount_factors(const double& d_t1, const double& d_t2,
							 const double& time);
double term_structure_forward_rate_from_yields(const double& r_t1, const double& r_t2, 
					       const double& t1, const double& t2);
double term_structure_yield_linearly_interpolated(const double& time, 
						  const vector<double>& obs_times, 
						  const vector<double>& obs_yields);
// a term structure class


class term_structure_class {
public:
    virtual double yield(const double& t) const;
    virtual double discount_factor(const double& t) const;
    virtual double forward_rate(const double& t1, const double& t2) const;
};

class term_structure_class_flat : public term_structure_class {
private: 
    double R_;                              // interest rate
public:
    term_structure_class_flat(const double& r);
    virtual double yield(const double& t) const;
    void set_int_rate(const double& r);
};

class term_structure_class_interpolated : public term_structure_class {
private: 
    vector<double> times_;     // use to keep a list of yields
    vector<double> yields_;
    void clear();
public:
    term_structure_class_interpolated();
    term_structure_class_interpolated(const vector<double>& times, const vector<double>& yields);
    virtual ~term_structure_class_interpolated();
    term_structure_class_interpolated(const term_structure_class_interpolated&);
    term_structure_class_interpolated operator= (const term_structure_class_interpolated&);

    int no_observations() const { return times_.size(); };
    virtual double yield(const double& T) const;
    void set_interpolated_observations(vector<double>& times, vector<double>& yields);
};

// using the term structure classes

double bonds_price(const vector<double>& cashflow_times,  
		   const vector<double>& cashflows,
		   const term_structure_class& d); 

double bonds_duration(const vector<double>& cashflow_times,
		      const vector<double>& cashflow_amounts,
		      const term_structure_class& d); 

double bonds_convexity(const vector<double>& cashflow_times,
		       const vector<double>& cashflow_amounts,
		       const term_structure_class& d); 

//// Futures pricing
double futures_price(const double& S, const double& r, const double& time_to_maturity);

/// Binomial option pricing 

double option_price_call_european_binomial( const double& S, const double& K, const double& r,   
					    const double& u, const double& d);  // one periode binomial 

double option_price_call_european_binomial( const double& S, const double& K, const double& r,
					    const double& u, const double& d, const int& no_periods);
    // multiple periode binomial 

vector< vector<double> > binomial_tree(const double& S0, const double& u,const double& d, 
				       const int& no_steps);

/// Black Scholes formula //////////////////////////////////////////

double option_price_call_black_scholes(const double& S, const double& K, const double& r,
				       const double& sigma, const double& time) ;
double option_price_put_black_scholes (const double& S, const double& K, const double& r, 
				       const double& sigma, const double& time) ;

double 
option_price_implied_volatility_call_black_scholes_newton( const double& S, const double& K,
							   const double& r, const  double& time, 
							   const double& option_price);

double option_price_implied_volatility_call_black_scholes_bisections( const double& S, const double& K,
								      const double& r, const double& time, 
								      const double& option_price);
double option_price_delta_call_black_scholes(const double& S, const double& K, const double& r, 
					     const double& sigma, const double& time);
double option_price_delta_put_black_scholes (const double& S, const double& K, const double& r,
					     const double& sigma, const double& time);
void option_price_partials_call_black_scholes(const double& S, const double& K, const double& r, 
					      const double& sigma, const double& time, 
					      double& Delta, double& Gamma, double& Theta,
					      double& Vega, double& Rho);
void option_price_partials_put_black_scholes(const double& S, const double& K, const double& r, 
					     const double& sigma, const double& time,
					     double& Delta, double& Gamma, double& Theta, 
					     double& Vega, double& Rho);

/// warrant price
double warrant_price_adjusted_black_scholes(const double& S, const double& K,  
					    const double& r, const double& sigma, 
					    const double& time, 
					    const double& no_warrants_outstanding,
					    const double& no_shares_outstanding);

double warrant_price_adjusted_black_scholes(const double& S, const double& K,  
					    const double& r, const double& q, 
					    const double& sigma, const double& time, 
					    const double& no_warrants_outstanding,
					    const double& no_shares_outstanding);

/// Extensions of the Black Scholes model //////////////

double option_price_european_call_payout(const double& S, const double& K, const double& r,
					 const double& b, const double& sigma, const double& time);
double option_price_european_put_payout (const double& S, const double& K, const double& r,
					 const double& b, const double& sigma, const double& time);
double option_price_european_call_dividends(const double& S, const double& K, const double& r, 
					    const double& sigma, const double& time,
					    const vector<double>& dividend_times, 
					    const vector<double>& dividend_amounts );
double option_price_european_put_dividends( const double& S, const double& K, const double& r, 
					    const double& sigma,const double& time,
					    const vector<double>& dividend_times, 
					    const vector<double>& dividend_amounts);
double option_price_american_call_one_dividend(const double& S, const double& K, const double& r, 
					       const double& sigma,
					       const double& tau, const double& D1, const double& tau1);
double futures_option_price_call_european_black(const double& F, const double& K, const double& r, 
						const double& sigma, const double& time);
double futures_option_price_put_european_black(const double& F, const double& K, const double& r, 
					       const double& sigma, const double& time);
double currency_option_price_call_european(const double& S, const double& K, const double& r,
					   const double& r_f, const double& sigma, const double& time);
double currency_option_price_put_european(const double& S, const double& K, const double& r, 
					  const double& r_f, const double& sigma, const double& time);
double option_price_american_perpetual_call(const double& S, const double& K, const double& r,
					    const double& q, const double& sigma);
double option_price_american_perpetual_put(const double& S, const double& K, const double& r,
					   const double& q, const double& sigma);

// binomial option approximation ////////////////

double option_price_call_european_binomial(const double& S, const double& K, const double& r, 
					   const double& sigma, const double& t, const int& steps);
double option_price_put_european_binomial (const double& S, const double& K, const double& r, 
					   const double& sigma, const double& t, const int& steps);
double option_price_call_american_binomial(const double& S, const double& K, const double& r, 
					   const double& sigma, const double& t, const int& steps);
double option_price_put_american_binomial (const double& S, const double& K, const double& r, 
					   const double& sigma, const double& t, const int& steps);
double option_price_call_american_binomial(const double& S, const double& K, 
					   const double& r, const double& y,
					   const double& sigma, const double& t, const int& steps);
double option_price_put_american_binomial (const double& S, const double& K, const double& r, 
					   const double& y, const double& sigma, 
					   const double& t, const int& steps);
 
double option_price_call_american_discrete_dividends_binomial( const double& S, const double& K, 
							       const double& r,
							       const double& sigma,  const double& t, 
							       const int& steps, 
							       const vector<double>& dividend_times,
							       const vector<double>& dividend_amounts);

double option_price_put_american_discrete_dividends_binomial(const double& S, const double& K, 
							     const double& r, 
							     const double& sigma,  const double& t,
							     const int& steps, 
							     const vector<double>& dividend_times, 
							     const vector<double>& dividend_amounts);

double option_price_call_american_proportional_dividends_binomial(const double& S, const double& K,
								  const double& r,  const double& sigma,
								  const double& time, const int& no_steps,
								  const vector<double>& dividend_times,
								  const vector<double>& dividend_yields);

double option_price_put_american_proportional_dividends_binomial( const double& S, const double& K, const double& r,
								  const double& sigma, const double& time, const int& no_steps,
								  const vector<double>& dividend_times,
								  const vector<double>& dividend_yields); 

double option_price_delta_american_call_binomial(const double& S, const double& K, const double& r,  
						 const double& sigma, const double& t, const int& no_steps);
double option_price_delta_american_put_binomial(const double& S, const double& K, const double& r,  
						const double& sigma, const double& t, const int& no_steps);
void option_price_partials_american_call_binomial(const double& S, const double& K, const double& r,    
						  const double& sigma, const double& time, const int& no_steps,
						  double& delta, double& gamma, double& theta,
						  double& vega, double& rho);  
 
void option_price_partials_american_put_binomial(const double& S, const double& K, const double& r,    
						 const double& sigma, const double& time, const int& no_steps,
						 double& delta, double& gamma, double& theta,
						 double& vega, double& rho);  

double futures_option_price_call_american_binomial(const double& F, const double& K, const double& r, const double& sigma,
						   const double& time, const int& no_steps);

double futures_option_price_put_american_binomial( const double& F, const double& K, const double& r, const double& sigma,
						   const double& time, const int& no_steps);

double currency_option_price_call_american_binomial( const double& S, const double& K, const double& r, const double& r_f, 
						     const double& sigma, const double& t, const int& n);

double currency_option_price_put_american_binomial( const double& S, const double& K, const double& r, const double& r_f,
						    const double& sigma, const double& t, const int& n);

//////////////////// finite differences //////////////////

double option_price_call_american_finite_diff_explicit( const double& S, const double& K, const double&  r,
							const double& sigma, const double& time, 
							const int& no_S_steps, const int& no_t_steps);

double option_price_put_american_finite_diff_explicit( const double& S, const double& K, const double&  r, 
						       const double& sigma, const double& time, 
						       const int& no_S_steps, const int& no_t_steps);

double option_price_call_european_finite_diff_explicit( const double& S, const double& K, const double&  r,
							const double& sigma, const double& time, 
							const int& no_S_steps, const int& no_t_steps);

double option_price_put_european_finite_diff_explicit( const double& S, const double& K, const double&  r, 
						       const double& sigma, const double& time, 
						       const int& no_S_steps, const int& no_t_steps);

double option_price_call_american_finite_diff_implicit( const double& S, const double& K, const double& r,
							const double& sigma, const double& time, 
							const int& no_S_steps, const int& no_t_steps);

double option_price_put_american_finite_diff_implicit( const double& S, const double& K, const double& r,
						       const double& sigma, const double& time, 
						       const int& no_S_steps, const int& no_t_steps);

double option_price_call_european_finite_diff_implicit( const double& S, const double& K, const double& r,
							const double& sigma, const double& time, 
							const int& no_S_steps, const int& no_t_steps);

double option_price_put_european_finite_diff_implicit( const double& S, const double& K, const double& r,
						       const double& sigma, const double& time, 
						       const int& no_S_steps, const int& no_t_steps);

///////////////////////// simulated option prices //////////////////////////////////////
// Payoff only function of terminal price
double option_price_call_european_simulated(const double& S, const double& K,
					    const double& r, const double& sigma,
					    const double& time_to_maturity, const int& no_sims);
double option_price_put_european_simulated(const double& S, const double& K,
					   const double& r, const double& sigma,
					   const double& time_to_maturity, const int& no_sims);
double option_price_delta_call_european_simulated(const double& S, const double& K,
						  const double& r, const double& sigma,
						  const double& time_to_maturity, const int& no_sims);
double option_price_delta_put_european_simulated(const double& S, const double& K,
						 const double& r, const double& sigma,
						 const double& time_to_maturity, const int& no_sims);
double simulate_lognormal_random_variable(const double& S, const double& r, const double& sigma,
					  const double& time);

double 
derivative_price_simulate_european_option_generic( const double& S, const double& K,
						   const double& r, const double& sigma,
						   const double& time,
						   double payoff(const double& price, const double& K),
						   const int& no_sims); 
double 
derivative_price_simulate_european_option_generic_with_control_variate(const double& S, const double& K,
								       const double& r,const double& sigma,
								       const double& time,
								       double payoff(const double& price,
										     const double& K),
								       const int& no_sims); 

double 
derivative_price_simulate_european_option_generic_with_antithetic_variate(const double& S, const double& K,
									  const double& r,
									  const double& sigma,
									  const double& time,
									  double payoff(const double&price,
											const double& K),
									  const int& no_sims); 
/////////////////////////////
// payoffs of various options, to be used as function arguments in above simulations
double payoff_call(const double& price, const double& K);
double payoff_put (const double& price, const double& K);
double payoff_cash_or_nothing_call(const double& price, const double& K);
double payoff_asset_or_nothing_call(const double& price, const double& K);
 
/////////// approximated option prices ////////////////////////

double option_price_american_call_approximated_baw(const double& S, const double& K, 
						   const double& r, const double& b, 
						   const double& sigma, const double& time);
double option_price_american_put_approximated_baw(const double& S, const double& K, 
						  const double& r, const double& b, 
						  const double& sigma, const double& time);


////////////// path dependent and other exotic options ////////////////////////////////

double option_price_call_bermudan_binomial(const double& S, const double& X, const double& r,
					    const double& q, const double& sigma, const double& time, 
					    const vector<double>& potential_exercise_times,
					    const int& steps);

double option_price_put_bermudan_binomial( const double& S, const double& X, const double& r, 
					   const double& q, const double& sigma, const double& time, 
					   const vector<double>& potential_exercise_times,
					   const int& steps);

double option_price_european_lookback_call(const double& S, const double& Smin,  const double& r,
					   const double& q, const double& sigma,  const double& time);

double option_price_european_lookback_put(const double& S, const double& Smin, const double& r,
					  const double& q, const double& sigma, const double& time);


double 
option_price_asian_geometric_average_price_call(const double& S, const double& K, const double& r,
						const double& q, const double& sigma, const double& time);

vector<double> simulate_lognormally_distributed_sequence(const double& S, const double& r,  
							 const double& sigma, const double& time,  const int& no_steps);
double 
derivative_price_simulate_european_option_generic( const double& S, const double& K, const double& r, 
						   const double& sigma, const double& time,
						   double payoff(const vector<double>& price,
								 const double& K),
						   const int& no_steps, const int& no_sims); 


double 
derivative_price_simulate_european_option_generic_with_control_variate(const double& S, const double& K,
								       const double& r, const double& sigma,
								       const double& time,
								       double payoff(const vector<double>& price,
										     const double& K),
								       const int& nosteps, const int& nosims); 


/////////////////////////////
// payoffs of various options, to be used as function arguments in above simulations

double payoff_arithmetric_average_call(const vector<double>& prices, const double& K);
double payoff_geometric_average_call(const vector<double>& prices, const double& K);
double payoff_lookback_call(const vector<double>& prices, const double& unused_variable);
double payoff_lookback_put(const vector<double>& prices, const double& unused_variable);

/////////////////// alternative stochastic processes ////////////////

double option_price_call_merton_jump_diffusion( const double& S, const double& K, const double& r, 
						const double& sigma, const double& time_to_maturity,
						const double& lambda, const double& kappa, const double& delta);

// fixed income derivatives,  GBM assumption on bond price

double bond_option_price_call_zero_black_scholes(const double& B, const double& K, const double& r,
						 const double& sigma, const double& time);
double bond_option_price_put_zero_black_scholes(const double& B, const double& K, const double& r, 
						const double& sigma, const double& time);
double bond_option_price_call_coupon_bond_black_scholes(const double& B, const double& K, const double& r, 
							const double& sigma, const double& time, 
							const vector<double> coupon_times, 
							const vector<double> coupon_amounts);
double bond_option_price_put_coupon_bond_black_scholes(const double& B, const double& K, const double& r,
						       const double& sigma, const double& time, 
						       const vector<double> coupon_times,
						       const vector<double> coupon_amounts);
double bond_option_price_call_american_binomial( const double& B, const double& K, const double& r, 
						const double& sigma, const double& t, const int& steps); 
double bond_option_price_put_american_binomial( const double& B, const double& K, const double& r, 
						const double& sigma, const double& t, const int& steps); 

////////////////////////////////////////////////////////////////////////////////
// term structure models
/// formulas for calculation

double term_structure_yield_nelson_siegel(const double& t,
					  const double& beta0, const double& beta1, const double& beta2,
					  const double& lambda );


double term_structure_discount_factor_cubic_spline(const double& t,
						   const double& b1,
						   const double& c1,
						   const double& d1,
						   const vector<double>& f,
						   const vector<double>& knots);

double term_structure_discount_factor_cir(const double& t, const double& r,
					  const double& kappa,
					  const double& lambda,
					  const double& theta,
					  const double& sigma);

double term_structure_discount_factor_vasicek(const double& time,
					      const double& r,
					      const double& a,const double& b, const double& sigma);

/// defining classes wrapping the above term structure approximations
 
class term_structure_class_nelson_siegel : public term_structure_class {
private: 
    double beta0_, beta1_, beta2_, lambda_;
public:
    term_structure_class_nelson_siegel(const double& beta0,  const double& beta1,
				       const double& beta2,  const double& lambda);
    virtual double yield(const double& t) const;
};

class term_structure_class_cubic_spline : public term_structure_class {
private: 
    double b_; double c_; double d_; vector<double> f_; vector<double> knots_;
public:
    term_structure_class_cubic_spline(const double& b, const double& c, const double& d, 
				      const vector<double>& f, const vector<double> & knots);
    virtual ~term_structure_class_cubic_spline();
    virtual double discount_factor(const double& t) const;
};

class term_structure_class_cir : public term_structure_class {
private: 
    double r_;  double kappa_;  double lambda_; double theta_; double sigma_;
public:
    term_structure_class_cir(const double& r, const double& k, const double& l,
			     const double& th,const double& sigma);
    virtual double discount_factor(const double& t) const;
};

class term_structure_class_vasicek : public term_structure_class {
private: 
    double r_; double a_; double b_; double sigma_;
public:
    term_structure_class_vasicek(const double& r, const double& a, const double& b, const double& sigma);
    virtual double discount_factor(const double& T) const;
};

/////////////////
/// binomial term structure models
/// bond option, rendlemann bartter  (binomial)

double 
bond_option_price_call_zero_american_rendleman_bartter(const double& K, const double& option_maturity,  
						       const double& S, const double& M, 
						       const double& interest, 
						       const double& bond_maturity,
						       const double& maturity_payment,
						       const int& no_steps);

/////////////////////////////////
// term structure derivatives, analytical solutions

double bond_option_price_call_zero_vasicek(const double& X, const double& r,
					   const double& option_time_to_maturity,
					   const double& bond_time_to_maturity,
					   const double& a, const double& b, const double& sigma);  
double bond_option_price_put_zero_vasicek(const double& X, const double& r,
					  const double& option_time_to_maturity,
					  const double& bond_time_to_maturity,
					  const double& a, const double& b, const double& sigma);  
#endif
