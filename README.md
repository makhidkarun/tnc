     TNC(1x)                                                     TNC(1x)



     NAME
          tnc - Random trade & commerce data generator for MegaTraveller

     SYNOPSIS
          tnc out_file

     DESCRIPTION
          Tnc is a trade & commerce generator which produces random
          lists of freight, cargo, and passengers, based on attributes
          of a source and destination star-system pair, plus the abilities
          of the crew negotiating for those goods.

     PARAMETERS
          Tnc expects 1 parameter, which is an output filename where
          the randomly generated data will be written.

     INPUT
         Tnc is an interactive program and solicits information from
	 the user which it uses to modify it's output.  The user will
	 be prompted for the following information:

	     o  The UWP of the source world.

	     o  The following skill levels for the crew of the freighter
		bidding for the goods: Steward, Admin, Streetwise, Broker,
		and Liaison.

	     o  The population of the destination world.

	     o  The Tech. level of the destination world.

	     o  Whether or not the destination world is an Amber or
		Red Zone.

     NON-STANDARD BEHAVIOR

	 Tnc applies additional cost modifiers to Major, Minor, and
	 Incidental cargo lots, to add 'flavor' to the results.  All
	 prices for Natural Resource cargos are multiplied by 40%, prices
	 for Processed Resource cargos are multiplied by 70%, prices for
	 Information cargos are multiplied by 110%, and prices for
	 Novelty cargos are multiplied by 200%.  Since these modifiers
	 produce exactly the same effect on sale as they do on purchase,
	 they have no effect on the game other than adding 'local color'.
	 If you do not wish to use them, they can easily be removed from
	 the source code.  Each 2-line section of code is enclosed by
	 comments reading "NON-STANDARD MT cost modifiers", and can easily
	 be deleted.

     AUTHOR
          Tnc was developed by Mark F. Cook, Hewlett-Packard Company
          (markc@hpcvss.cv.hp.com).
